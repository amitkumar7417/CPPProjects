#include "stdafx.h"
#include "searching.h"
using namespace Searching;

int main()
{
	vector<int> num1 = { 1,2,3,4,5,6,7,8,3 };
	bool isDuplicatePresent = CheckDuplicate(num1);
	cout << "Is duplicate = " << isDuplicatePresent << endl;
	vector<int> num2 = { 1,2,3,4,5,6,7,8 };
	isDuplicatePresent = CheckDuplicate(num2);
	cout << "Is duplicate = " << isDuplicatePresent << endl;


	isDuplicatePresent = CheckDuplicate2(num1);
	cout << "Is duplicate = " << isDuplicatePresent << endl;
	isDuplicatePresent = CheckDuplicate2(num2);
	cout << "Is duplicate = " << isDuplicatePresent << endl;

	isDuplicatePresent = CheckDuplicate3(num1);
	cout << "Is duplicate = " << isDuplicatePresent << endl;
	isDuplicatePresent = CheckDuplicate3(num2);
	cout << "Is duplicate = " << isDuplicatePresent << endl;

	vector<int> num3 = { 1,1,3,3,3,5,5,5,5,1,7,1,8,3,3,4 };
	pair<int,int> max_repeated = FindMaxRepeatedNumber(num3);
	cout << "Max repeated number is " << max_repeated.first << " and repeated " << max_repeated.second << " times"<< endl;
	
	max_repeated = FindMaxRepeatedNumber2(num3);
	cout << "Max repeated number is " << max_repeated.first << " and repeated " << max_repeated.second << " times" << endl;

	max_repeated = FindMaxRepeatedNumber3(num3);
	cout << "Max repeated number is " << max_repeated.first << " and repeated " << max_repeated.second << " times" << endl;

	vector<int> num4 = {3,2,1,2,2,3};
	int firstRepeated = FindFirstRepeatedNumber(num4);
	cout << "First repeated number = " << firstRepeated << endl;

	firstRepeated = FindFirstRepeatedNumber2(num4);
	cout << "First repeated number = " << firstRepeated << endl;

	vector<int> num5 = {1,2,4,6,3,7,8};
	int missingNumber = FindMissingNumber(num5);
	cout << "Missing number = " << missingNumber << endl;

	missingNumber = FindMissingNumber2(num5);
	cout << "Missing number = " << missingNumber << endl;

	missingNumber = FindMissingNumber3(num5);
	cout << "Missing number = " << missingNumber << endl;

	missingNumber = FindMissingNumber4(num5);
	cout << "Missing number = " << missingNumber << endl;

	missingNumber = FindMissingNumber5(num5);
	cout << "Missing number = " << missingNumber << endl;

	vector<int> num6 = {1,2,3,2,3,1,3};
	int numOddOccurence = FindNumberOccuringOddTimes(num6);
	cout << "Number which is occuring odd number of times = " << numOddOccurence << endl;

	vector<int> num7 = { 4,15,7,18,14,12,1,3,7 };
	pair<int, int> pairWithSumK = FindTwoElementsWithSumK(num7, 30);
	cout << "Pair with sum 30 : { " << pairWithSumK.first << " , " << pairWithSumK.second << " }" << endl;

	pairWithSumK = FindTwoElementsWithSumK2(num7, 30);
	cout << "Pair with sum 30 : { " << pairWithSumK.first << " , " << pairWithSumK.second << " }" <<endl;

	pairWithSumK = FindTwoElementsWithSumK3(num7, 30);
	cout << "Pair with sum 30 : { " << pairWithSumK.first << " , " << pairWithSumK.second << " }" <<endl;

	vector<int> num8 = {1,60,-10,70,-80,85};
	pair<int, int> pairCloseToZero = FindPairWithSumClosestToZero(num8);
	cout << "Pair with sum close to zero : { " << pairCloseToZero.first << " , " << pairCloseToZero.second << " }" << endl;

	pairCloseToZero = FindPairWithSumClosestToZero1(num8);
	cout << "Pair with sum close to zero : { " << pairCloseToZero.first << " , " << pairCloseToZero.second << " }" << endl;
	
	vector<int> num9 = { 4,15,7,18,14,12,1,3,7 };
	int sum_3 = 45;
	vector<int> out;
	Find3NumbersWithSumK(num9, sum_3,out);
	if (out.size() > 0) {
		cout << "Three numers with sum " << sum_3 <<  " are : { " << out[0] << "," << out[1] << "," << out[2] << " } " << endl;
	}
	else {
		cout << "Three numbers with sum " << sum_3 << " cannot be found" << endl;
	}

	out.clear();
	Find3NumbersWithSumK1(num9, sum_3, out);
	if (out.size() > 0) {
		cout << "Three numers with sum " << sum_3 << " are : { " << out[0] << "," << out[1] << "," << out[2] << " } " << endl;
	}
	else {
		cout << "Three numbers with sum " << sum_3 << " cannot be found" << endl;
	}

	return 0;
}
