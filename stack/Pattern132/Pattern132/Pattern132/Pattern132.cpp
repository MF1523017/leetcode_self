// Pattern132.cpp : 定义控制台应用程序的入口点。
/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

	Note: n will be less than 15, 000.

	Example 1 :
	Input : [1, 2, 3, 4]

	Output : False

	Explanation : There is no 132 pattern in the sequence.
	Example 2 :
	Input : [3, 1, 4, 2]

	Output : True

	Explanation : There is a 132 pattern in the sequence : [1, 4, 2].
	Example 3 :
	Input : [-1, 3, 2, 0]

	Output : True

	Explanation : There are three 132 patterns in the sequence : [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].*/
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<vector>
#include<ctime>
using std::vector;
using std::stack;
//i = 6, nums = [9, 11, 8, 9, 10, 7, 9], S1 candidate = 9, S3 candidate = None, Stack = Empty
//i = 5, nums = [9, 11, 8, 9, 10, 7, 9], S1 candidate = 7, S3 candidate = None, Stack = [9]
//i = 4, nums = [9, 11, 8, 9, 10, 7, 9], S1 candidate = 10, S3 candidate = None, Stack = [9, 7]
//i = 3, nums = [9, 11, 8, 9, 10, 7, 9], S1 candidate = 9, S3 candidate = 9, Stack = [10]
//i = 2, nums = [9, 11, 8, 9, 10, 7, 9], S1 candidate = 8, S3 candidate = 9, Stack = [10, 9] We have 8<9, sequence found!
class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int s3 = INT_MIN;
		stack<int> st;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] < s3) return true;
			else while (!st.empty() && nums[i] > st.top()) {
				s3 = st.top(); st.pop();
			}
			st.push(nums[i]);
		}
		return false;
	}
};
int main()
{
	clock_t start = clock();
	vector<int> nums({ 9, 11, 8, 9, 10, 7,9 });
	Solution test;
	std::cout << test.find132pattern(nums) << std::endl;
	clock_t end = clock();
	std::cout << "runtime is "<<end-start << std::endl;
    return 0;
}

