#pragma once
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
	int diff = (1 << 30) - 1;
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size(); ++i)
	{
		int re = target - nums[i];
		int left = i + 1;
		int right = nums.size() - 1;
		while (left<right)
		{
			int mid = (left + right) / 2;
			int sum = nums[left] + nums[right];
			if (sum>re)
			{
				if (diff < 0) {
					if (-diff > sum - re)
						diff = sum - re;
				}
				else
				{
					diff = min(diff, sum - re);
				}
				--right;
			}
			else if (sum<re)
			{
				if (diff > 0) {
					if (-diff < sum - re)
						diff = sum-re;
				}
				else
				{
					diff = max(diff, sum - re);
				}
				++left;
				
			}
			else
				return target;
		}

	}
	return target + diff;
}

void testSolution()
{
	vector<int> nums({ 1,2,4,8,16,32,64,128 });
	cout << threeSumClosest(nums, 82) << endl;
}
