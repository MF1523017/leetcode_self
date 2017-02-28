// SpiralMatrix.cpp : 定义控制台应用程序的入口点。
	/*Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix :

[
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9]
]*/
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
 /*When traversing the matrix in the spiral order, at any time we follow one out of the following four directions : RIGHT DOWN LEFT UP.
Suppose we are working on a 5 x 3 matrix as such :

0 1 2 3 4 5
6 7 8 9 10
11 12 13 14 15

Imagine a cursor starts off at(0, -1), i.e.the position at '0', then we can achieve the spiral order by doing the following :

Go right 5 times
Go down 2 times
Go left 4 times
Go up 1 times.
Go right 3 times
Go down 0 times->quit
Notice that the directions we choose always follow the order 'right->down->left->up',
and for horizontal movements, the number of shifts follows : {5, 4, 3}, and vertical movements follows{ 2, 1, 0 }.*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())return vector<int>();
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> res;
		vector<vector<int>> dirs({ { 0,1 }, {1,0},{0,-1},{-1,0} });//right,down,left,up;
		vector<int> nsteps{ col,row - 1 };
		int idir = 0;
		int ir = 0, ic = -1;
		while (nsteps[idir % 2])
		{
			for (int i = 0; i < nsteps[idir % 2]; ++i)
			{
				ir += dirs[idir][0];
				ic += dirs[idir][1];
				res.push_back(matrix[ir][ic]);
			}
			nsteps[idir % 2]--;
			idir = (idir + 1) % 4;
		}
		return res;
	}
};

int main()
{

    return 0;
}

