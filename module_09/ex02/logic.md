1.	Group into pairs of two. Use 1 comparision between each pair to split into a larger and a smaller vector.
	smaller vector gets appended the lost number if it was uneven at the end
2.	Recursively sort the large vector using the same method
3.	Insert the small elements back into the large vector, using binary search to find a place.
	// jacobsthal sequence needs to be used here somehow. dont know how yet.

to reinsert:
 
int jacobs_index (starts at 1 because e already inserted first small element)
int i = 0; (index in pend)
always save previous i into a new variable, s
to find the next number to insert, use jacobsthal(jacobs_index) * 2.
- while inserting, set lower bound (0) and upper bound (paired large number for efficient binary search)
loop back and insert until i == s.
then, increment jacobs_index, and set i, and continue.

s, i
0, 2
0, 1
2, 4
2, 3
4, 9
4, 8