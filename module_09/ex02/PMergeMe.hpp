/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 05:19:48 by fschuber          #+#    #+#             */
/*   Updated: 2024/09/12 05:46:11 by fschuber         ###   ########.fr       */
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

	private:
		std::vector<int> mergeAndInsert(std::vector<int> a1, std::vector<int> a2);
		int binarySearch(std::vector<int> a, int target);
		std::vector<int> insertionSort(std::vector<int> a);
};
