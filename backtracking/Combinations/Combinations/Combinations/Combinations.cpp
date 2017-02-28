

// Combinations.cpp : 定义控制台应用程序的入口点。
 /*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is :

[
	[2, 4],
	[3, 4],
	[2, 3],
	[1, 2],
	[1, 3],
	[1, 4],
]*/
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		if (n<k) return res;
		vector<int> tmp(0, 0);
		helper(res, tmp, 0, 0, n, k);
		return res;
	}
	void helper(vector<vector<int>> &res, vector<int> &tmp, int start, int num, int n, int k)
	{
		if (num == k)
		{
			res.push_back(tmp);
			return;
		}
		for (int i = start; i<n; ++i)
		{
			tmp.push_back(i + 1);
			helper(res, tmp, i + 1, num + 1, n, k);
			tmp.pop_back();
		}
	}

};

int main()
{
	Solution test;
	test.combine(4, 2);
    return 0;
}

