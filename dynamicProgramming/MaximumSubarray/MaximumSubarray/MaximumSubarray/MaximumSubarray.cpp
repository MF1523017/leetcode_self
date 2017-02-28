// MaximumSubarray.cpp : 定义控制台应用程序的入口点。
 /*Find the contiguous subarray within an array(containing at least one number) which has the largest sum.

For example, given the array[-2, 1, -3, 4, -1, 2, 1, -5, 4],
the contiguous subarray[4, -1, 2, 1] has the largest sum = 6.*/
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1)return nums[0];
		int thisSum, maxSum;
		thisSum = 0;
		maxSum = nums[0];
		for (int i = 0; i<nums.size(); ++i)
		{
			thisSum += nums[i];
			if (thisSum > maxSum)
				maxSum = thisSum;
			if (thisSum<0)
				thisSum = 0;
		}
		return maxSum;
	}
};
int main()
{
	Solution test;
	vector<int> nums({ -3,-2,0,-1 });
	std::cout<<test.maxSubArray(nums)<<std::endl;
    return 0;
}

