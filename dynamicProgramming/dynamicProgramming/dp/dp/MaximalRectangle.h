#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using std::max;
using std::vector;
class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		int res = 0;
		vector<vector<int>> dp(row, vector<int>(col, 0));
		dp[0][0] = matrix[0][0] - '0';
		for (int i = 1; i<col; ++i)
		{
			if ('0' == matrix[0][i])
				dp[0][i] = 0;
			else
				dp[0][i] = dp[0][i - 1] + 1;
		}
		for (int i = 1; i<row; ++i)
		{
			if ('0' == matrix[i][0])
				dp[i][0] = 0;
			else
				dp[i][0] = dp[i - 1][0] + 1;
		}
		for (int i = 1; i<row; ++i)
		{
			for (int j = 1; j<col; ++j)
			{
				if ('0' == matrix[i][j])
					dp[i][j] = 0;
				else
				{
					if (dp[i - 1][j] == 0 && dp[i][j - 1] != 0)
					{
						dp[i][j] = 1 + dp[i][j - 1] - dp[i - 1][j - 1];
					}
					if (dp[i - 1][j] != 0 && dp[i][j - 1] == 0)
					{
						dp[i][j] = 1 + dp[i - 1][j] - dp[i - 1][j - 1];
					}
					if (dp[i - 1][j] == 0 && dp[i][j - 1] == 0)
					{
						dp[i][j] = 1;
					}
					if (dp[i - 1][j] != 0 && dp[i][j - 1] != 0) {
						if(dp[i-1][j-1]==0)
							dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
						else
							dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 2;
					}
				}
			}
		}
		for (int i = 0; i<row; ++i)
		{
			for (int j = 0; j<col; ++j)
			{
				if (dp[i][j]>res)
					res = dp[i][j];
			}
		}
		return res;
	}
};


void testSolution()
{

	int *p = new int[10];
	vector<vector<char>> matrix({ {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0' } });
	Solution s;
	std::cout << s.maximalRectangle(matrix) << std::endl;
}