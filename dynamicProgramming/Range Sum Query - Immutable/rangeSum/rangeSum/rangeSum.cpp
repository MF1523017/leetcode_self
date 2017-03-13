// rangeSum.cpp : 定义控制台应用程序的入口点。
//
 /*Given an integer array nums, find the sum of the elements between indices i and j(i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> - 1
sumRange(0, 5) -> - 3*/
#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
class NumArray {
public:
	NumArray(vector<int> nums) {
		_data.swap(nums);
	}

	int sumRange(int i, int j) {
		vector<int> res(_data.size(), 0);
		res[0] = _data[0];
		for (int k = 1; k<_data.size(); ++k)
		{
			res[k] = res[k - 1] + _data[k];
		}
		return res[j] - res[i];
	}
private:
	vector<int> _data;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/

int main()
{
	//Your NumArray object will be instantiated and called as such :
	vector<int>nums({ -2,0,3,-5,2,-1 });
	NumArray *obj = new NumArray(nums);
	int param_1 = obj->sumRange(0, 2);
    return 0;
}

