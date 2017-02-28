// minMove.cpp : 定义控制台应用程序的入口点。
//Given a non - empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
//
//You may assume the array's length is at most 10,000.
//
//Example:
//
//Input:
//[1, 2, 3]
//
//Output :
//	2
//
//	Explanation :
//	Only two moves are needed(remember each move increments or decrements one element) :
//
//	[1, 2, 3] = >[2, 2, 3] = >[2, 2, 2]
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::min_element;
class Solution {
public:
	//找中位数
	int minMoves3(vector<int>& nums) {
		int n = nums.size();
		auto it = nums.begin() + n / 2;
		nth_element(nums.begin(), it, nums.end());
		int median = *it;
		int total = 0;
		for (auto &i : nums)
			total += abs(i - median);
		return total;
	}
	int minMoves2(vector<int>& nums) {
		int minV = *min_element(nums.begin(), nums.end());
		int sum = 0;
		vector<int> distance;
		for (auto n : nums)
		{
			distance.push_back(n - minV);
			sum += n - minV;
		}
		int step = 1;

		while (true)
		{
			int n = 0;
			int p = 0;
			for (auto d : distance)
			{
				int newD = d - step;
				if (newD < 0)
					n++;
				else
					p++;
			}

			if (n >= p)
			{
				break;
			}
			else
			{
				sum -= p - n;
			}
			++step;
		}
		return sum;
	}
};
int main()
{
	vector<int> nums({ 9,32,5,12 });
	Solution test;
	cout<<test.minMoves3(nums)<<endl;
    return 0;
}

