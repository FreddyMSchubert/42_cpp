/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgerling <cgerling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:07:24 by rmarquar          #+#    #+#             */
/*   Updated: 2024/05/10 14:51:12 by cgerling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
std::cout << GREEN << "Copy Constructor called" << OFF << std::endl;
*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
std::cout << GREEN << "Assignment Constructor called" << OFF << std::endl;
(void)other;
return *this;
}

// function to sort the array
// from Robin Marquardt
void insertionSort(std::vector<int>& arr, int start, int end)
{
	int i = start + 1;

	while (i <= end)
	{
		int value = arr[i];
		int j = i - 1;
		while (j >= start && arr[j] > value)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = value;
		++i;
	}
}

// function to merge the array
// first i create a list from the array and then i merge the list
// back to the array
void merge(std::vector<int>& arr, int left, int middle, int right)
{
	int LeftNr = middle - left + 1;
	int RightNr = right - middle;

	std::vector<int> Left(LeftNr), Right(RightNr);

	int i = 0;
	while (i < LeftNr)
	{
		Left[i] = arr[left + i];
		++i;
	}

	int j = 0;
	while (j < RightNr)
	{
		Right[j] = arr[middle + 1 + j];
		++j;
	}

	i = 0;
	j = 0;
	int k = left;

	while (i < LeftNr && j < RightNr)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			++i;
		}
		else
		{
			arr[k] = Right[j];
			++j;
		}
		++k;
	}

	while (i < LeftNr)
	{
		arr[k] = Left[i];
		++i;
		++k;
	}

	while (j < RightNr)
	{
		arr[k] = Right[j];
		++j;
		++k;
	}
}

// Ford-Jonson Algorithm decides whether to use InsertionSort or MergeSort
// if the size of the array is less than or equal to k, then it uses InsertionSort immdiatly
// otherwise it uses MergeSort with the recursive call to itself until the size of the array is less than or equal to k
// in the lese case, we call the recursive function with the left and right half of the array
// from Robin Marquardt
void PmergeMe::fordJohnsonAlgorithm(std::vector<int>& arr, int left, int right, int breakEven)
{
	if (left < right)
	{
		if (right <= breakEven)
		{
			insertionSort(arr, left, right);
		}

		else
		{
			int middle = left + (right - left) / 2;
			PmergeMe::fordJohnsonAlgorithm(arr, left, middle, breakEven);
			PmergeMe::fordJohnsonAlgorithm(arr, middle + 1, right, breakEven);
			merge(arr, left, middle, right);
		}
	}
}

// function to sort the list
// i use the same logic as the one above, but i use list instead of vector
// from Robin Marquardt
template<class Iterator>
void insertionSortL(std::list<int>& arr, Iterator start, Iterator end)
{
	(void)arr;
	if (start == end) return;

	Iterator it = start;
	++it;
	while (it != end)
	{
		int value = *it;
		Iterator j = it;
		Iterator prev = j;
		--prev;
		while (j != start && *prev > value)
		{
			int temp = *j;
			*j = *prev;
			*prev = temp;
			--j;
			--prev;
		}
		if (*prev > value)
		{
			int temp = *j;
			*j = *prev;
			*prev = temp;
		}
		++it;
	}
}

// function to merge the list
// first i create two lists from the list and then i merge the lists
// back to the list
// from Robin Marquardt
void mergeL(std::list<int>& arr, std::list<int>::iterator left, std::list<int>::iterator middle, std::list<int>::iterator right)
{
	(void)arr;
	int LeftNr = 0;
	int RightNr = 0;

	std::list<int>::iterator it = left;
	while (it != middle)
	{
		++LeftNr;
		++it;
	}
	it = middle;
	while (it != right)
	{
		++RightNr;
		++it;
	}

	std::list<int> Left(left, ++middle);
	std::list<int> Right(middle, ++right);

	std::list<int>::iterator i = Left.begin();
	std::list<int>::iterator j = Right.begin();
	std::list<int>::iterator k = left;

	while (i != Left.end() && j != Right.end())
	{
		if (*i <= *j)
		{
			*k = *i;
			++i;
		}
		else
		{
			*k = *j;
			++j;
		}
		++k;
	}

	while (i != Left.end())
	{
		*k = *i;
		++i;
		++k;
	}

	while (j != Right.end())
	{
		*k = *j;
		++j;
		++k;
	}
}

// Ford-Jonson Algorithm decides whether to use InsertionSort or MergeSort
// if the size of the list is less than or equal to k, then it uses InsertionSort immdiatly
// otherwise it uses MergeSort with the recursive call to itself until the size of the list is less than or equal to k
// this function is similar to the one above, but it uses list instead of vector
// from Robin Marquardt
void PmergeMe::fordJohnsonAlgorithmL(std::list<int>& arr, int left, int right, int breakEven)
{
	if (left < right)
	{
		if (right <= breakEven)
		{
			std::list<int>::iterator leftIt = arr.begin();
			std::advance(leftIt, left);
			std::list<int>::iterator rightIt = arr.begin();
			std::advance(rightIt, right);
			insertionSortL(arr, leftIt, rightIt);
		}
		else
		{
			int middle = left + (right - left) / 2;
			PmergeMe::fordJohnsonAlgorithmL(arr, left, middle, breakEven);
			PmergeMe::fordJohnsonAlgorithmL(arr, middle + 1, right, breakEven);
			std::list<int>::iterator leftIt = arr.begin();
			std::advance(leftIt, left);
			std::list<int>::iterator middleIt = arr.begin();
			std::advance(middleIt, middle);
			std::list<int>::iterator rightIt = arr.begin();
			std::advance(rightIt, right);
			mergeL(arr, leftIt, middleIt, rightIt);
		}
	}
}
