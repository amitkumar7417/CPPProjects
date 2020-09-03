// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sorting.h"
namespace Sorting {
	void BubbleSort(std::vector<int> & num) {
		//Input : {6,5,3,1,8,7,2,4}
		int len = num.size();
		for (int i = len - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				//Compare and swap
				if (num[j] > num[j + 1]) {
					int tmp = num[j + 1];
					num[j + 1] = num[j];
					num[j] = tmp;
				}
			}
		}
	}

	void BubbleSortImproved(std::vector<int> &num) {
		//Input : {6,5,3,1,8,7,2,4}
		int len = num.size();
		int swapped = 1;
		for (int i = len - 1; i >= 0 && swapped; i--) {
			swapped = 0;
			for (int j = 0; j < i; j++) {
				//Compare and swap
				if (num[j] > num[j + 1]) {
					int tmp = num[j + 1];
					num[j + 1] = num[j];
					num[j] = tmp;
					swapped = 1;
				}
			}
		}
		
	}

	void SelectionSort(std::vector<int> &num) {
		//Input : {6,5,3,1,8,7,2,4}
		int len = num.size();
		for (int i = 0; i < len; i++) {
			int min = i;
			for (int j = i+1; j < len; j++) {
				if (num[j] < num[min]) {
					min = j;
				}
			}
			//Swap 
			if (i != min) {
				int temp = num[i];
				num[i] = num[min];
				num[min] = temp;
			}
		}
	}

	void InsertionSort(std::vector<int> &num) {
		//Input : {6,5,3,1,8,7,2,4}
		int len = num.size();
		for (int i = 0; i < len; i++) {
			int val = num[i];
			int j = i;
			while (j >=1 && num[j-1] > val) {
				num[j] = num[j-1];
				j--;
			}
			num[j] = val;
		}
	}

	void ShellSort(std::vector<int> &num) {
		//Input : {6,5,3,1,8,7,2,4}
		int len = num.size();
	
		vector<int> steps;
		int step = len;
		do {
			step = step / 2;
			if (step < 1) {
				step = 1;
			}
			steps.push_back(step);
		}while (step != 1);

		for (const auto& step : steps) {
			for (int i = step; i < len; i++) {
				int val = num[i];
				int j = i;
				while (j >= step && num[j-step] > val ) {
					num[j] = num[j-step];
					j = j - step;
				}
				num[j] = val;
			}
		}

	}

	// Array A[] has the items to sort; array B[] is a work array.
	void TopDownMergeSort(vector<int>&A, vector<int>&B, int n)
	{
		B = vector<int>(A.begin(), A.end());           // one time copy of A[] to B[]
		TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
	}

	// Sort the given run of array A[] using array B[] as a source.
	// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
	void TopDownSplitMerge(vector<int>& B, int iBegin, int iEnd, vector<int>& A)
	{
		if (iEnd - iBegin <= 1)                       // if run size == 1
			return;                                 //   consider it sorted
													// split the run longer than 1 item into halves
		int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
														// recursively sort both runs from array A[] into B[]
		TopDownSplitMerge(A, iBegin, iMiddle, B);  // sort the left  run
		TopDownSplitMerge(A, iMiddle, iEnd, B);  // sort the right run
												 // merge the resulting runs from array B[] into A[]
		TopDownMerge(B, iBegin, iMiddle, iEnd, A);
	}

	//  Left source half is A[ iBegin:iMiddle-1].
	// Right source half is A[iMiddle:iEnd-1   ].
	// Result is            B[ iBegin:iEnd-1   ].
	void TopDownMerge(vector<int>& A, int iBegin, int iMiddle, int iEnd, vector<int> &B)
	{
		int i = iBegin, j = iMiddle;

		// While there are elements in the left or right runs...
		for (int k = iBegin; k < iEnd; k++) {
			// If left run head exists and is <= existing right run head.
			if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
				B[k] = A[i];
				i = i + 1;
			}
			else {
				B[k] = A[j];
				j = j + 1;
			}
		}
	}


	int Partition(vector<int>& A, int low, int high) {
		//Lomuto partition scheme.
		//This scheme degrades to O(n2) when the array is already in order.
		int pivot = A[high]; //Select right most element as the pivot element.
		int i = low;
		for (int j = low; j < high; j++) {
			if (A[j] < pivot) {
				//Swap
				int temp = A[j];
				A[j] = A[i];
				A[i] = temp;
				i++;
			}
		}
		//Swap pivot element at index i;
		A[high] = A[i];
		A[i] = pivot;

		return i;
	}

	void QuickSort(vector<int>& A, int low, int high) {
		int pivot;
		if (high > low) {
			pivot = Partition(A, low, high);
			QuickSort(A, low, pivot - 1);
			QuickSort(A, pivot + 1, high);
		}
	}
}


