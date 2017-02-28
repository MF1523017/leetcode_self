// firstMissingPos.cpp : 定义控制台应用程序的入口点。
//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given[1, 2, 0] return 3,
//and[3, 4, -1, 1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using std::vector;

//Put each number in its right place.
//
//For example :
//
//When we find 5, then swap it with A[4].
//
//At last, the first place where its number is not right, return the place + 1.

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++)
			while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
				swap(nums[i], nums[nums[i] - 1]);
		for (int i = 0; i < n; i++)
			if (nums[i] != i + 1)
				return i + 1;
		return n + 1;
	}
private:
	void swap(int &a, int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};

int main()
{
	Solution test;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(1);
	std::cout<<test.firstMissingPositive(nums)<<std::endl;
    return 0;
}

