1.	Group into pairs of two. Use 1 comparision between each pair to split into a larger and a smaller vector.
	smaller vector gets appended the lost number if it was uneven at the end
2.	Recursively sort the large vector using the same method
3.	Insert the small elements back into the large vector, using binary search to find a place.
	// jacobsthal sequence needs to be used here somehow. dont know how yet.