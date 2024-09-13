/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:19:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/13 09:38:13 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

// FORD JOHNSON MERGE INSERTION SORT

/* ----- VECTOR ----- */

std::vector<int> PMergeMe::mergeInsertionSort(std::vector<int> input)
{
	// Defined Cases
	if (input.size() == 1 || input.size() == 0)
		return input;
	if (input.size() == 2)
	{
		if (input[0] > input[1])
		{
			int temp = input[0];
			input[0] = input[1];
			input[1] = temp;
		}
		return input;
	}

	// Determine Straggler
	int straggler = 0;
	bool has_straggler = false;
	if (input.size() % 2 != 0)
	{
		straggler = input.back();
		input.pop_back();
		has_straggler = true;
	}

	// Split input into pairs
	std::vector<std::vector<int>> pairs;
	for (int i = 0; i < input.size(); i += 2)
	{
		std::vector<int> pair;
		pair.push_back(input[i]);
		pair.push_back(input[i + 1]);
		pairs.push_back(pair);
	}

	// Sort pairs using 1 comp per pair
	// Larger number takes larger index
	for (int i = 0; i < pairs.size(); i++)
	{
		if (pairs[i][0] > pairs[i][1])
		{
			int temp = pairs[i][0];
			pairs[i][0] = pairs[i][1];
			pairs[i][1] = temp;
		}
	}

	// Sort pairs by larger value
}

std::vector<std::vector<int>> PMergeMe::recursiveInsertSortPairs(std::vector<std::vector<int>> pairs)
{
	if (pairs.size() <= 1)
		return pairs;
	
	int mid = pairs.size() / 2;
	std::vector<std::vector<int>> left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::vector<int>> right(pairs.begin() + mid, pairs.end());

	left = recursiveInsertSortPairs(left);
	right = recursiveInsertSortPairs(right);

	// Merge

	std::vector<std::vector<int>> sorted;
}

/* ----- UTILS ----- */
int	PMergeMe::jacobsthalSequence(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return jacobsthalSequence(n - 1) + 2 * jacobsthalSequence(n - 2);
}
