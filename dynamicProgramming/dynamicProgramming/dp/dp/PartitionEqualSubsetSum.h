#pragma once
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;
		vector<bool>dp(sum / 2 + 1, false);
		dp[0] = true;
		int tmp = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			tmp = nums[i];
			for (int j = dp.size()-1; j>=0; --j)
			{
				if (j+tmp>sum / 2)
					continue;
				if (dp[j])
					dp[j + tmp] = true;
			}
		}
		return dp[sum / 2];
	}
};
void testSolution()
{
	cout << (4 >> 2) << endl;
	vector<int> nums{ 1,2,3,4,5,6,7 };
	Solution s;
	cout << s.canPartition(nums) << endl;
}