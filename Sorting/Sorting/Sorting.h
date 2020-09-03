#pragma once
#include "stdafx.h"

namespace Sorting {
	void BubbleSort(std::vector<int>& num);
	void BubbleSortImproved(std::vector<int>& num);
	void SelectionSort(std::vector<int>& num);
	void InsertionSort(std::vector<int>& num);
	void ShellSort(std::vector<int>& num);
	void TopDownMergeSort(vector<int>&A, vector<int>&B, int n);
	void TopDownSplitMerge(vector<int>& B, int iBegin, int iEnd, vector<int>& A);
	void TopDownMerge(vector<int>& A, int iBegin, int iMiddle, int iEnd, vector<int> &B);
	void QuickSort(vector<int>& A, int low, int high);
	int Partition(vector<int>& A, int low, int high);
};