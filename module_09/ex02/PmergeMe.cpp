/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:19:27 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 20:07:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

/* ----- VECTOR ----- */

std::vector<int> PMergeMe::mergeInsertionSort(std::vector<int> a)
{
	if (a.size() <= 1)
		return a;
	else if (a.size() <= THRESHOLD)
		return insertionSort(a);

	int mid = a.size() / 2;
	std::vector<int> a1 = mergeInsertionSort(std::vector<int>(a.begin(), a.begin() + mid));
	std::vector<int> a2 = mergeInsertionSort(std::vector<int>(a.begin() + mid, a.end()));

	return mergeAndInsert(a1, a2);
}

std::vector<int> PMergeMe::mergeAndInsert(std::vector<int> a1, std::vector<int> a2)
{
	std::vector<int> result;
	result.reserve(a1.size() + a2.size());

	int j = 0;
	for (int elem : a1)
	{
		int pos = binarySearch(a2, elem);
		result.insert(result.end(), a2.begin() + j, a2.begin() + pos);
	}

	result.insert(result.end(), a2.begin(), a2.end());

	return result;
}

int PMergeMe::binarySearch(std::vector<int> a, int target)
{
	int low = 0;
	int high = a.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (a[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

std::vector<int> PMergeMe::insertionSort(std::vector<int> a)
{
	for (int i = 1; i < (int)a.size(); i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	return a;
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
