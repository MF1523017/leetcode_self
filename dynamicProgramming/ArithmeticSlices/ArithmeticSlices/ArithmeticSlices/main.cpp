#include<iostream>
#include<vector>
#include<numeric>
using std::accumulate;
using std::vector;
using std::cout;
using std::endl;
//
//A sequence of number is called arithmetic 
//if it consists of at least three elements 
//and if the difference between any two consecutive elements is the same.
//
//For example, these are arithmetic sequence :
//
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//The following sequence is not arithmetic.
//
//1, 1, 2, 5, 7
//
//A zero - indexed array A consisting of N numbers is given.A slice of that array is any pair of integers(P, Q) such that 0 <= P < Q < N.
//
//	A slice(P, Q) of array A is called arithmetic if the sequence :
//A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic.In particular, this means that P + 1 < Q.
//
//	The function should return the number of arithmetic slices in the array A.
//
//
//	Example :
//
//	A = [1, 2, 3, 4]
//
//	return : 3, for 3 arithmetic slices in A : [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
class Solution {
public:
	//动态规划，每次新增加一个数值的时候，如果还能是arithmetic，那么 dp[i]=dp[i-1]+1;
	int numberOfArithmeticSlices1(vector<int>& A) {
		vector<int> _result(A.size(), 0);
		int diff = A[1] - A[0];
		for (unsigned i = 2; i < A.size(); ++i)
		{
			if (A[i] - A[i - 1] == diff)
			{
				_result[i] = _result[i - 1] + 1;
			}
			else
			{
				diff = A[i] - A[i - 1];
			}
		}
		return accumulate(_result.begin(), _result.end(), 0);
	}
	bool Arithmetic(vector<int> &a, int start, int end)
	{
		int diff = a[start + 1] - a[start];
		for (int i = start+1; i<=end; ++i)
		{
			if (diff != a[i] - a[i - 1])
				return false;
		}
		return true;
	}
	int numberOfArithmeticSlices(vector<int>& A) {
		int _result = 0;
		for (unsigned i = 0; i<A.size(); ++i)
		{
			for (unsigned j = i + 2; j<A.size(); ++j)
			{
				if (Arithmetic(A, i, j))
					_result++;
			}
		}

		return _result;
	}
};
int main(int argc, char **argv)
{
	Solution test;
	vector<int>A({1,2,3,4});
	cout << test.numberOfArithmeticSlices1(A) << endl;
	return 0;
}