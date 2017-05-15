#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
namespace std
{
	template<>
	struct hash<vector<int>>
	{
		size_t operator()(const vector<int> &rhs)const noexcept
		{
			return(51 + std::hash<int>()(rhs.size() * 51));
		}
	};
};
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty())return res;
		unordered_set<vector<int>> _res;
		size_t size = nums.size();
		for (unsigned int i = 0; i<pow(2, size); ++i)
		{
			vector<int>tmp;
			for (unsigned int j = 0; j<size; ++j)
			{
				if (((i >> j) & 1) == 1)
				{
					tmp.push_back(nums[j]);
				}
			}
			_res.insert(tmp);
		}
		for (auto it = _res.begin(); it != _res.end(); ++it)
		{
			res.push_back(*it);
		}
		cout << res.size() << endl;
		return res;
	}
};

void testSolution()
{
	Solution s;
	vector<int>nums{ 4,4,4,1,4};
	auto res=s.subsetsWithDup(nums);
	return;
}
