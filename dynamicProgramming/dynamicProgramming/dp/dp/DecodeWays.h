#pragma once

#include<iostream>
#include<string>
#include<vector>
using std::vector;
using std::string;
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())return 0;
		if (s[0] == '0')return 0;
		vector<int> dp(s.size()+1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i < s.size() + 1; ++i)
		{
			int tmp = s[i - 1] - '0';
			if (tmp != 0)
				dp[i] = dp[i - 1];
			if (s[i - 2] != '0')
			{
				tmp = std::stoi(s.substr(i - 2, 2));
				if(tmp>0&&tmp<=26)
					dp[i] += dp[i - 2];
		}
		}
		return dp[s.size()];
	}
};

void testSolution()
{
	printf("%s , %5.3s\n", "computer", "computer");
	string s("100");
	Solution test;
	std::cout<<test.numDecodings(s)<<std::endl;
}