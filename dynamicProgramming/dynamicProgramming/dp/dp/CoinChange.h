#pragma once
#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty())return -1;
		vector<int>dp(amount + 1, -1);
		dp[0] = 0;
		for (size_t i = 0; i <= amount; ++i)
		{
			if (dp[i] != -1)
			{
				for (size_t j = 0; j<coins.size(); ++j)
				{
					if (i + coins[j]>amount)
						continue;
					if (dp[i + coins[j]] == -1)
						dp[i + coins[j]] = dp[i] + 1;
					else
					{
						dp[i + coins[j]] = dp[i + coins[j]]<dp[i] + 1 ? dp[i + coins[j]] : dp[i] + 1;
					}
				}
			}
		}
		return dp[amount];
	}
};
void testSolution()
{
	Solution s;
	vector<int> coins{ 1,2147483647 };
	std::cout<<s.coinChange(coins, 2)<<std::endl;
}

