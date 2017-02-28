// Diagonal_Traverse.cpp : 定义控制台应用程序的入口点。
//Given a matrix of M x N elements(M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//Example:
//Input:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//Output : [1, 2, 4, 7, 5, 3, 6, 8, 9]
//	Explanation :
//
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())return vector<int>();
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> result;
		if (row == 1 || col == 1)
		{
			for (auto b : matrix)
			{
				for (auto n : b)
					result.push_back(n);
			}
			return result;
		}
		result.push_back(matrix[0][0]);
		int sum_ij = 1;
		
		int i = 0;
		int j = 0;
		while (true)
		{
			if (i == 0 )
			{
				if (j != col-1) {
					while (sum_ij - i >= 0 && i < row) {
						j = sum_ij - i;
						result.push_back(matrix[i][j]);
						i++;
					}
					i--;
				}
				else
				{
					j = col - 1;
					while (j>=0&&sum_ij - j >= 0 && sum_ij - j<row)
					{
						i = sum_ij - j;
						result.push_back(matrix[i][j]);
						j--;
					}
					j++;
				}
				
				sum_ij++;
			}
			else if (j == 0)
			{
				if (i != row-1) {
					while (sum_ij - j >= 0 && j < col)
					{
						i = sum_ij - j;
						result.push_back(matrix[i][j]);
						j++;
					}
					j--;
				}
				else
				{
					i = row - 1;
					while (i>=0&&sum_ij - i >= 0 && sum_ij - i<col)
					{
						j = sum_ij - i;
						result.push_back(matrix[i][j]);
						i--;
					}
					i++;
				}
				
				sum_ij++;
			}
			else if (j == col - 1)
			{
				while (j>=0&&sum_ij - j >= 0 && sum_ij - j<row)
				{
					i = sum_ij - j;
					result.push_back(matrix[i][j]);
					j--;
				}
				j++;
				sum_ij++;
			}
			else if (i == row - 1)
			{
				while (i>=0&&sum_ij - i >= 0 && sum_ij - i<col)
				{
					j = sum_ij - i;
					result.push_back(matrix[i][j]);
					i--;
				}
				i++;
				sum_ij++;
			}
			if (sum_ij>row + col - 2)
				break;
		}
		return result;
	}
};

int main()
{
	vector<vector<int>> matrix({{1,2,3,4,5,6,7,8,9,10 }, { 11,12,13,14,15,16,17,18,19,20 }});
	Solution test;
	auto result=test.findDiagonalOrder(matrix);
	for (auto n : result)
		cout << n << " ";
    return 0;
}

