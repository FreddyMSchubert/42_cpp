template<
    typename RandomAccessIterator,
    typename Compare
>
auto merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last,
                               Compare compare)
{
    // Cache all the differences between a Jacobsthal number and its
    // predecessor that fit in 64 bits, starting with the difference
    // between the Jacobsthal numbers 4 and 3 (the previous ones are
    // unneeded)
    static constexpr std::uint_fast64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    using std::iter_swap;

    auto size = std::distance(first, last);
    if (size < 2) return;

    // Whether there is a stray element not in a pair
    // at the end of the chain
    bool has_stray = (size % 2 != 0);

    ////////////////////////////////////////////////////////////
    // Group elements by pairs

    auto end = has_stray ? std::prev(last) : last;
    for (auto it = first ; it != end ; it += 2)
    {
        if (compare(it[1], it[0]))
        {
            iter_swap(it, it + 1);
        }
    }

    ////////////////////////////////////////////////////////////
    // Recursively sort the pairs by max

    merge_insertion_sort_impl(
        make_group_iterator(first, 2),
        make_group_iterator(end, 2),
        compare
    );

    ////////////////////////////////////////////////////////////
    // Separate main chain and pend elements

    // The first pend element is always part of the main chain,
    // so we can safely initialize the list with the first two
    // elements of the sequence
    std::list<RandomAccessIterator> chain = { first, std::next(first) };

    // Upper bounds for the insertion of pend elements
    std::vector<typename std::list<RandomAccessIterator>::iterator> pend;
    pend.reserve((size + 1) / 2 - 1);

    for (auto it = first + 2 ; it != end ; it += 2)
    {
        auto tmp = chain.insert(std::end(chain), std::next(it));
        pend.push_back(tmp);
    }

    // Add the last element to pend if it exists; when it
    // exists, it always has to be inserted in the full chain,
    // so giving it chain.end() as end insertion point is ok
    if (has_stray)
    {
        pend.push_back(std::end(chain));
    }

    ////////////////////////////////////////////////////////////
    // Binary insertion into the main chain

    auto current_it = first + 2;
    auto current_pend = std::begin(pend);

    for (int k = 0 ; ; ++k)
    {
        // Should be safe: in this code, std::distance should always return
        // a positive number, so there is no risk of comparing funny values
        using size_type = std::common_type_t<
            std::uint_fast64_t,
            typename std::list<RandomAccessIterator>::difference_type
        >;

        // Find next index
        auto dist = jacobsthal_diff[k];
        if (dist > static_cast<size_type>(std::distance(current_pend, std::end(pend)))) break;

        auto it = std::next(current_it, dist * 2);
        auto pe = std::next(current_pend, dist);

        do
        {
            --pe;
            it -= 2;

            auto insertion_point = std::upper_bound(
                std::begin(chain), *pe, *it,
                [=](const auto& lhs, const auto& rhs) {
                    return compare(lhs, *rhs);
                }
            );
            chain.insert(insertion_point, it);
        } while (pe != current_pend);

        std::advance(current_it, dist * 2);
        std::advance(current_pend, dist);
    }

    // If there are pend elements left, insert them into
    // the main chain, the order of insertion does not
    // matter so forward traversal is ok
    while (current_pend != std::end(pend))
    {
        auto insertion_point = std::upper_bound(
            std::begin(chain), *current_pend, *current_it,
            [=](const auto& lhs, const auto& rhs) {
                return compare(lhs, *rhs);
            }
        );
        chain.insert(insertion_point, current_it);
        current_it += 2;
        ++current_pend;
    }

    ////////////////////////////////////////////////////////////
    // Move values in order to a cache then back to origin

    std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
    cache.reserve(size);

    for (auto&& it: chain)
    {
        auto begin = it.base();
        auto end = begin + it.size();
        std::move(begin, end, std::back_inserter(cache));
    }
    std::move(std::begin(cache), std::end(cache), first.base());
}