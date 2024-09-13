/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:19:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/13 16:19:30 by fschuber         ###   ########.fr       */
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
		comparisonsCount++;
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
	for (int i = 0; i < (int)input.size(); i += 2)
	{
		std::vector<int> pair;
		pair.push_back(input[i]);
		pair.push_back(input[i + 1]);
		pairs.push_back(pair);
	}

	// Sort pairs using 1 comp per pair
	// Larger number takes larger index
	for (int i = 0; i < (int)pairs.size(); i++)
	{
		comparisonsCount++;
		if (pairs[i][0] > pairs[i][1])
		{
			int temp = pairs[i][0];
			pairs[i][0] = pairs[i][1];
			pairs[i][1] = temp;
		}
	}

	// Sort pairs by larger value
	pairs = recursiveInsertSortPairs(pairs);

	// Creation of S & pend
	std::vector<int> S;
	std::vector<int> pend;
	for (int i = 0; i < (int)pairs.size(); i++)
	{
		pend.push_back(pairs[i][0]);
		S.push_back(pairs[i][1]);
	}
	if (has_straggler)
		pend.push_back(straggler);
	
	// --- MERGE ---

	// First element of pend can be added to S without comparison
	S.insert(S.begin(), pend[0]);
	
	int jacobs_index = 0;
	int pend_index = 0;
	int prev_pend_index = 0;
	int prev_max_pend_index = 0;

	while (prev_pend_index < (int)pend.size() - 1)
	{
		if (pend_index == prev_pend_index)
		{
			jacobs_index++;
			prev_pend_index = prev_max_pend_index;
			pend_index = jacobsthalSequence(jacobs_index) - 1;
			prev_max_pend_index = pend_index;
		}
		else
		{
			pend_index--;
		}
		while (pend_index >= (int)pend.size())
			pend_index--;
		if (prev_pend_index >= (int)pend.size() - 1)
			break;
		if (pend_index == prev_pend_index)
			continue;

		int insertIndex = binarySearch(S, pend[pend_index], S.size() - 1);
		std::cout << pend[pend_index] << std::endl;
		S.insert(S.begin() + insertIndex, pend[pend_index]);
	}

	return S;
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

	int i = 0;
	int j = 0;

	while (i < (int)left.size() && j < (int)right.size())
	{
		comparisonsCount++;
		if (left[i][1] < right[j][1])
		{
			sorted.push_back(left[i]);
			i++;
		}
		else
		{
			sorted.push_back(right[j]);
			j++;
		}
	}

	while (i < (int)left.size())
		sorted.push_back(left[i++]);
	while (j < (int)right.size())
		sorted.push_back(right[j++]);

	return sorted;
}

int PMergeMe::binarySearch(std::vector<int> arr, int item, int upperBound)
{
	int low = 0;
	int high = upperBound;
	int mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		comparisonsCount++;
		if (arr[mid] == item)
			return mid;
		comparisonsCount++;
		if (arr[mid] < item)
			low = mid + 1;
		else
			high = mid - 1;
	}

	return low;
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

int PMergeMe::getComparisonsCount()
{
	return comparisonsCount;
}
