#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//For example, given the following matrix :
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())return 0;
		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>>dp(row, vector<int>(col, 0));
		for (int i = 0; i<row; ++i)
			dp[i][0] = matrix[i][0] - '0';
		for (int i = 0; i<col; ++i)
			dp[0][i] = matrix[0][i] - '0';
		for (int i = 1; i<row; ++i)
		{
			for (int j = 1; j<col; ++j)
			{
				if (dp[i - 1][j - 1] == 0)
					dp[i][j] = matrix[i][j] - '0';
				else
				{
					int len = static_cast<int>(sqrt(dp[i - 1][j - 1]));
					if (h(matrix, i, j, len) && w(matrix, i, j, len) && matrix[i][j]!='0')
					{
						dp[i][j] = (len + 1)*(len + 1);
					}
					else {
						if (matrix[i][j] == '1'&&matrix[i][j - 1] == '1'&&matrix[i - 1][j] == '1')
							dp[i][j] = matrix[i][j] = 4;
						else
							dp[i][j] = matrix[i][j] - '0';
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i<row; ++i)
		{
			for (int j = 0; j<col; ++j)
				res = max(res, dp[i][j]);
		}
		return res;
	}
	bool h(vector<vector<char>>&matrix, int i, int j, int len)
	{
		while (len)
		{
			if (matrix[i][j - len] == '0')
				return false;

			--len;
		}
		return true;
	}
	bool w(vector<vector<char>>&matrix, int i, int j, int len)
	{
		while (len)
		{
			if (matrix[i - len][j] == '0')
				return false;
			--len;
		}
		return true;
	}
};
void testSolution()
{
	vector<vector<char>> matrix({ {'0' ,'0' ,'0', '1'},
								{'1', '1', '0' ,'1'  },
								{'1', '1', '1', '1' },
								{'0' ,'1' ,'1' ,'1' },
								{'0','1','1','1'} });
	
	Solution s;
	cout<<s.maximalSquare(matrix)<<endl;
}
