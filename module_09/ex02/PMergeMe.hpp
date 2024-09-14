/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:19:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/14 17:28:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>

#define THRESHOLD 10

class PMergeMe
{
	public:
		PMergeMe() = default;
		~PMergeMe() = default;
		PMergeMe(const PMergeMe&) = default;
		PMergeMe& operator=(const PMergeMe&) = default;

		std::vector<int> mergeInsertionSort(std::vector<int> a);
		std::deque<int> mergeInsertionSort(std::deque<int> a);
		int getComparisonsCount();

	private:
		unsigned int	comparisonsCount = 0;

		int	jacobsthalSequence(int n);
		int binarySearch(std::vector<int> arr, int item);
		int binarySearch(std::deque<int> arr, int item);
		std::vector<std::vector<int>> recursiveInsertSortPairs(std::vector<std::vector<int>> pairs);
		std::deque<std::deque<int>> recursiveInsertSortPairs(std::deque<std::deque<int>> pairs);
};
