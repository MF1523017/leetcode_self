// Permutations II.cpp : 定义控制台应用程序的入口点。
	/*Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1, 1, 2] have the following unique permutations :
[
	[1, 1, 2],
	[1, 2, 1],
	[2, 1, 1]
]*/
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::swap;
using std::sort;
class Solution {
public:
	void recursion(vector<int> num, int i, vector<vector<int> > &res) {
		if (i == num.size() - 1) {
			res.push_back(num);
			return;
		}
		for (int k = i; k < num.size(); k++) {
			if (i != k && num[i] == num[k]) continue;
			swap(num[i], num[k]);
			recursion(num, i + 1, res);
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		recursion(num, 0, res);
		return res;
	}
};

int main()
{
	Solution test;
	vector<int> nums({1,1,2});
	auto result=test.permuteUnique(nums);
    return 0;
}

