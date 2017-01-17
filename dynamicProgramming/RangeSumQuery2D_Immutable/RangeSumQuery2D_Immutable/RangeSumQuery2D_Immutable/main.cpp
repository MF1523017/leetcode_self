//Given a 2D matrix matrix, 
//find the sum of the elements inside the rectangle 
//defined by its upper left corner(row1, col1) 
//and lower right corner(row2, col2).
//Example:
//Given matrix = [
//		[3, 0, 1, 4, 2],
//		[5, 6, 3, 2, 1],
//		[1, 2, 0, 1, 5],
//		[4, 1, 0, 1, 7],
//		[1, 0, 3, 0, 5]
//	]
//
//sumRegion(2, 1, 4, 3) -> 8
//sumRegion(1, 1, 2, 2) -> 11
//sumRegion(1, 2, 2, 4) -> 12


//
//sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] +
//
//matrix[i - 1][j - 1]
#include<iostream>
#include<vector>
using std::vector;
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		_row = matrix.size();
		_col = _row>0?matrix[0].size():0;
		_sum = vector<vector<int>>(_row + 1, vector<int>(_col + 1, 0));
		for (int i = 1;i<_row+1;++i)
		{
			for (int j = 1; j < _col + 1; ++j)
			{
				_sum[i][j] = _sum[i - 1][j] + _sum[i][j - 1] - _sum[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return _sum[row2 + 1][col2 + 1] - _sum[row2 + 1][col1] - _sum[row1][col2 + 1] + _sum[row1][col1];
	}

private:
	int _row, _col;
	vector<vector<int>> _sum;
};

int main(int argc, char **argv)
{
	vector<vector<int>> matrix;
	for (int i = 0; i < 10; ++i)
	{
		vector<int> _rows;
		for (int j = 0; j < 10; ++j)
		{
			_rows.push_back(j);
		}
		matrix.push_back(_rows);
	}

	NumMatrix nummatrix(matrix);
	std::cout<<nummatrix.sumRegion(0, 0, 1, 1)<<std::endl;
	std::cout << nummatrix.sumRegion(1, 2, 3,4) << std::endl;
	return 0;
}