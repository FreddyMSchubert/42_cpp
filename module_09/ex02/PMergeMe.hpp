/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:19:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/13 14:29:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#define THRESHOLD 10

class PMergeMe
{
	public:
		PMergeMe() = default;
		~PMergeMe() = default;
		PMergeMe(const PMergeMe&) = default;
		PMergeMe& operator=(const PMergeMe&) = default;

		std::vector<int> mergeInsertionSort(std::vector<int> a);
		int getComparisonsCount();

	private:
		unsigned int	comparisonsCount = 0;

		int	jacobsthalSequence(int n);
		int binarySearch(std::vector<int> arr, int item, int upperBound);
		std::vector<std::vector<int>> recursiveInsertSortPairs(std::vector<std::vector<int>> pairs);
};
