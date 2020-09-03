#include "stdafx.h"
#include "Sorting.h"

void Print(const vector<int>& num) {
	for (auto n : num) {
		std::cout << n << '\t';
	}
	std::cout << endl;
}


int main() {
	std::vector<int> num = {6,5,3,1,8,7,2,4};
	
	std::vector<int> num1 = std::vector<int>(num.begin(), num.end());
	cout << "Bubble Sort" << '\t';
	Sorting::BubbleSort(num1);
	Print(num1);
	
	std::vector<int> num2 = std::vector<int>(num.begin(), num.end());
	cout << "Bubble Sort(I)" << '\t';
	Sorting::BubbleSortImproved(num2);
	Print(num2);

	std::vector<int> num3 = std::vector<int>(num.begin(), num.end());
	cout << "Selection Sort" << '\t';
	Sorting::SelectionSort(num3);
	Print(num3);

	std::vector<int> num4 = std::vector<int>(num.begin(), num.end());
	cout << "Insertion Sort" << '\t';
	Sorting::InsertionSort(num4);
	Print(num4);

	std::vector<int> num5 = std::vector<int>(num.begin(), num.end());
	cout << "Shell Sort" << '\t';
	Sorting::ShellSort(num5);
	Print(num5);


	std::vector<int> num6 = std::vector<int>(num.begin(), num.end());
	cout << "Merge Sort" << '\t';
	vector<int> tmp;
	Sorting::TopDownMergeSort(num6, tmp, num6.size());
	Print(num6);

	//Quick Sort
	std::vector<int> num7 = std::vector<int>(num.begin(), num.end());
	cout << "Quick Sort" << '\t';
	Sorting::QuickSort(num7, 0, num7.size()-1);
	Print(num7);
}