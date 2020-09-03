// Searching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Searching.h"

namespace Searching {

	bool CheckDuplicate(const vector<int>& num) {
		//Problem 1: Using brute-force approach , Time Complexity = O(n2), Space Complexity = O(1)
		int len = (int)num.size();
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (num[i] == num[j]) {
					return true;
				}
			}
		}
		return false;
	}


	bool CheckDuplicate2(const vector<int>&num) {
		//Problem 2: Using sorting method, Time Complexity = O(nlogn), Space Complexity = O(1)
		int n = (int)num.size();
		vector<int> tmp = vector<int>(num.begin(), num.end());
		std::sort(tmp.begin(), tmp.end()); // O(nlogn)
		for (int i = 0; i < n-1; i++) {   //O(n)
			if (tmp[i] == tmp[i + 1])
				return true;
		}
		return false;
	}

	bool CheckDuplicate3(const vector<int> &num) {
		//Problem 3: Using hashing.   Time Complexity: O(n), Space Complexity : O(n)
		unordered_map<int,int> uMap;
		for (const auto& i : num) {
			if (uMap.find(i) == uMap.end()) {
				uMap[i] = 1;
			}
			else {
				return true;
			}
		}
		
		return false;
	}


	pair<int,int> FindMaxRepeatedNumber(const vector<int> &num) {
		//Problem 5: Brute Force approach. Time Complexity: O(n2) , Space Complexity : O(1)
		int n = (int)num.size();
		int max_count = -1;
		int local_count = 0;
		int index;
		for (int i = 0; i < n; i++) {
			local_count = 0;
			for (int j = 0; j < n; j++) {
				if (num[i] == num[j]) {
					++local_count;
				}
			}
			if (local_count > max_count) {
				max_count = local_count;
				index = i;
			}
		}

		return make_pair(num[index],max_count);
	}
	
	pair<int,int> FindMaxRepeatedNumber2(const vector<int> &num) {
		//Problem 6: Sorting approach. Time Complexity: O(nlogn) , Space Complexity : O(1)
		int n = (int)num.size();
		vector<int> temp = vector<int>(num.begin(),num.end());
		std::sort(temp.begin(), temp.end());

		int max_count = -1;
		int local_count = 1;
		int index;
		for (int i = 0; i < n-1; i++) {
			if (temp[i] == temp[i + 1]) {
				++local_count;
			}
			else {
				local_count = 1;
			}

			if (local_count > max_count) {
				max_count = local_count;
				index = i;
			}
		}

		return make_pair(temp[index],max_count);
	}
	pair<int, int> FindMaxRepeatedNumber3(const vector<int> &num) {
		//Problem 7: Hashing approach. Time Complexity: O(n) , Space Complexity : O(n)
		unordered_map<int, int> uMap;
		for (auto i : num) {
			uMap[i] = uMap[i] + 1;
		}

		int max_count = 0;
		int max_elem = -1;
		for (auto it = uMap.begin(); it != uMap.end(); it++) {
			if (it->second > max_count) {
				max_count = it->second;
				max_elem = it->first;
			}
		}
		return make_pair(max_elem, max_count);
	}

	int FindFirstRepeatedNumber(const vector<int>& num) {
		//Problem 9 : Brute Force Approach, Time Complexity = O(n2), Space Complexity : O(1)
		int n = (int)num.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (num[i] == num[j])
					return num[i];
			}
		}

	}

	int FindFirstRepeatedNumber2(const vector<int>& num) {
		//Problem 11. Hashing Approach, Time Complexity = O(n) , Space Compleity : O(n)
		int n = (int)num.size();
		unordered_map<int, int> uMap;
		for (const auto& i: num) {
			//First pass to create the hashtable
				uMap[i] = uMap[i]+1;
		}

		for (const auto &i : num) {
			//Second pass to check if the hashtable has frequency more than 1
			if (uMap[i] > 1)
				return i;
		}
	}

	int FindMissingNumber(const vector<int>& num) {
		//Problem 13 : Brute Force Approach, Time Complexity = O(n2), Space Complexity : O(1)
		bool found = false;
		int n = (int)num.size();
		for (int i = 1; i <= n+1; i++) {
			found = false;
			for (int j = 0; j < n; j++) {
				if (num[j] == i)
					found = true;
			}
			if (!found)
				return i;
		}

	}

	int FindMissingNumber2(const vector<int>& num) {
		//Problem 14: Sorting approach. Time Complexity: O(nlogn) , Space Complexity : O(1)
		int n = (int)num.size();
		vector<int> tmp = vector<int>(num.begin(), num.end());
		sort(tmp.begin(), tmp.end());
		for (int i = 0; i < n; i++) {
			if (tmp[i] != i + 1)
				return i + 1;
		}
	}

	int FindMissingNumber3(const vector<int>& num) {
		//Problem 15: Hashing approach. Time Complexity: O(n) , Space Complexity : O(n)
		int n = (int)num.size();
		unordered_map<int, int> uMap;
		for (int i = 0; i < n; i++) {
			uMap[num[i]] = 1;
		}
		for (int i = 1; i <= n+1; i++) {
			if (uMap.find(i) == uMap.end())
				return i;
		}	
	}

	int FindMissingNumber4(const vector<int>& num) {
	//Problem 16 : Using mathematical formula. Time Complexity: O(n), Space Complexity: O(1)
		int n = (int)num.size();
		int expectedSum = (n+1) * ((n+1) + 1) / 2;
		int sum = 0;
		for (const auto& i : num)
			sum = sum + i;

		return expectedSum - sum;
	}

	int FindMissingNumber5(const vector<int>& num) {
		//Problem 17: Using XOR technique . Time Complexity(O(max(m,n))), Space Complexity : O(1)
		int X = 0;
		int n = (int)num.size();
		for (int i = 1; i <= n+1; i++) {
			X = i ^ X;
		}
		for (const auto& i : num) {
			X = X ^ i;
		}
		return X;
	}

	int FindNumberOccuringOddTimes(const vector<int> &num){
		//Problem 18. Time Complexity = O(n), Space Complexity = O(1)
		int X = 0;
		for (const auto& i : num) {
			X = X ^ i;
		}
		return X;
	}

	pair<int, int> FindTwoElementsWithSumK(const vector<int>&num, const int& sum) {
		//Problem 25 .Brute Force Approach . Time Complexity = O(n2), Space Complexity = O(1)
		int n = (int)num.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((num[i] + num[j]) == sum)
					return make_pair(num[i], num[j]);
			}
		}

		return make_pair(-1, -1); //To denote there is no such pair exists in the input vector;

	}

	pair<int, int> FindTwoElementsWithSumK2(const vector<int>&num, const int& sum) {
		//Problem 26 .Sorting Approach . Time Complexity = O(nlogn), Space Complexity = O(1)
		vector<int> tmp = vector<int>(num.begin(), num.end());
		sort(tmp.begin(), tmp.end());
		int n = (int)num.size();
		int lo_ind = 0;
		int hi_ind = n - 1;
		while (lo_ind < hi_ind) {
			int val = tmp[lo_ind] + tmp[hi_ind];
			if (val == sum)
				return make_pair(tmp[lo_ind], tmp[hi_ind]);

			if (val < sum)
				lo_ind = lo_ind + 1;
			else
				hi_ind = hi_ind - 1;
		}

		return make_pair(-1, -1); //To denote there is no such pair exists in the input vector;

	}

	pair<int, int> FindTwoElementsWithSumK3(const vector<int>&num, const int& sum) {
		//Problem 28. Using Hashing. Time Complexity = O(n), Space Complexity = O(n)
		int n = (int)num.size();
		unordered_map<int, int> uMap;
		for (int i = 0; i < n; i++) {
			if (uMap.find(sum - num[i]) != uMap.end()) {
				return make_pair(num[i], sum - num[i]);
			}
			else {
				uMap[num[i]] = num[i];
			}
		}
		return make_pair(-1,-1);	
	}

	pair<int, int> FindPairWithSumClosestToZero(const vector<int>& num) {
		//Problem 30. Using Brute  Force. Time Complexity : O(n2), Space Complexity : O(1)
		int lowest_sum = INT_MAX;
		int num1, num2;
		int n = (int)num.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (abs(num[i] + num[j]) < lowest_sum) {
					lowest_sum = abs(num[i] + num[j]);
					num1 = num[i];
					num2 = num[j];
				}

			}
		}
		return make_pair(num1, num2);
	}

	pair<int, int> FindPairWithSumClosestToZero1(const vector<int>& num) {
		//Problem 31. Using Sorting. Time Complexity : O(nlogn) , Space Complexity : O(1)
		int n = (int)num.size();
		vector<int> tmp = vector<int>(num.begin(),num.end());
		sort(tmp.begin(), tmp.end());
		int negative_min = INT_MIN;
		int positive_min = INT_MAX;
		int lo_ind = 0;
		int hi_ind = n - 1;
		int num1, num2;
		int num3, num4;
		while (lo_ind < hi_ind) {
			int val = tmp[lo_ind] + tmp[hi_ind];
			if (val < 0) {
				if (val > negative_min) {
					negative_min = val;
					num1 = tmp[lo_ind];
					num2 = tmp[hi_ind];
				}
				++lo_ind;
			}
			else {
				if (val < positive_min) {
					positive_min = val;
					num3 = tmp[lo_ind];
					num4 = tmp[hi_ind];
				}
				--hi_ind;
			}
		}
		pair<int, int> output;
		if (abs(negative_min) < positive_min) {
			output.first = num1;
			output.second = num2;
		}
		else {
			output.first = num3;
			output.second = num4;
		}

		
		return output;
	}

	void Find3NumbersWithSumK(const vector<int>& num, const int& sum, vector<int> &out) {
		//Problem 32. Using Brute Force. Time Complexity : O(n3), Space Complexity : O(1)
		int n = (int)num.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (num[i] + num[j] + num[k] == sum) {
						out = {num[i],num[j],num[k]};
						return;
					}
				}
			}
		}

	}

	void Find3NumbersWithSumK1(const vector<int>& num, const int& sum, vector<int> &out) {
		//Problem 33. Using Sorting . Time Complexity : O(n2), Space Complexity : O(1)
		int n = (int)num.size();
		vector<int> tmp = vector<int>(num.begin(),num.end());
		sort(tmp.begin(), tmp.end());
		int lo_ind;
		int hi_ind; 
		for (int i = 0; i < n; i++) {
			lo_ind = i + 1;
			hi_ind = n - 1;
			while (lo_ind < hi_ind) {
				int local_sum = tmp[i] + tmp[lo_ind] + tmp[hi_ind];
				if (local_sum == sum) {
					out = { tmp[i],tmp[lo_ind],tmp[hi_ind] };
					return;
				}

				if (local_sum < sum) {
					++lo_ind;
				}
				else {
					--hi_ind;
				}
			}
		}

	}

	void Find3NumbersWithSumK2(const vector<int>& num, const int& sum, vector<int> &out) {
		//Problem 35. Hashing Technique. Time Complexity : , Space Complexity : 

	}

	
}
