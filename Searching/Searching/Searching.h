#pragma once
#include "stdafx.h"

namespace Searching {
	bool CheckDuplicate(const vector<int>& num);
	bool CheckDuplicate2(const vector<int>&num);
	bool CheckDuplicate3(const vector<int> &num);
	pair<int, int> FindMaxRepeatedNumber(const vector<int> &num);
	pair<int, int> FindMaxRepeatedNumber2(const vector<int> &num);
	pair<int, int> FindMaxRepeatedNumber3(const vector<int> &num);
	int FindFirstRepeatedNumber(const vector<int>& num);
	int FindFirstRepeatedNumber2(const vector<int>& num);
	int FindMissingNumber(const vector<int>& num);
	int FindMissingNumber2(const vector<int>& num);
	int FindMissingNumber3(const vector<int>& num);
	int FindMissingNumber4(const vector<int>& num);
	int FindMissingNumber5(const vector<int>& num);
	int FindNumberOccuringOddTimes(const vector<int> &num);
	pair<int, int> FindTwoElementsWithSumK(const vector<int>&num, const int& sum);
	pair<int, int> FindTwoElementsWithSumK2(const vector<int>&num, const int& sum);
	pair<int, int> FindTwoElementsWithSumK3(const vector<int>&num, const int& sum);
	pair<int, int> FindPairWithSumClosestToZero(const vector<int>& num);
	pair<int, int> FindPairWithSumClosestToZero1(const vector<int>& num);
	void Find3NumbersWithSumK(const vector<int>& num, const int& sum, vector<int> &out);
	void Find3NumbersWithSumK1(const vector<int>& num, const int& sum, vector<int> &out);
};