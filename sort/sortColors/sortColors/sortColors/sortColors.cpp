// sortColors.cpp : 定义控制台应用程序的入口点。
   /*Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up :
A rather straight forward solution is a two - pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one - pass algorithm using only constant space ?*/
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;
using std::swap;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zeros=0;
		int ones=0;
		int twos=0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] == 0)
				zeros++;
			if (nums[i] == 1)
				ones++;
			if (nums[i] == 2)
				twos++;
		}
		int i = 0;
		for (i; i<zeros; ++i)
			nums[i] = 0;
		for (i; i<zeros + ones; ++i)
			nums[i] = 1;
		for (i; i<zeros + ones + twos; ++i)
			nums[i] = 2;
	}
};
int main()
{
	vector<int> nums({0 });
	Solution test;
	test.sortColors(nums);
    return 0;
}

