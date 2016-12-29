#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>

using std::vector;
class Solution {
public:
	//O(N)的复杂度
	vector<int> twoSum1(vector<int>& numbers, int target) {
		int lo = 0, hi = numbers.size() - 1;
		while (numbers[lo] + numbers[hi] != target) {
			if (numbers[lo] + numbers[hi]<target) {
				lo++;
			}
			else {
				hi--;
			}
		}
		return vector<int>({ lo + 1,hi + 1 });
	}
	//先找到比target小的分界点（已经排好序了，使用二分查找，O(logN)复杂度），然后遍历一个更小的vector(O(K)<O(N))
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = getLessNumIndex(numbers, target);
		if (len == 0)
		{
			_result.push_back(1);
			_result.push_back(2);
			return _result;
		}
		int storeIndex = len - 1;
		int diffValue = target - numbers[storeIndex];
		for (int i = 0; i<storeIndex; ++i)
		{
			if (numbers[i] == diffValue) {
				_result.push_back(i+1);
				_result.push_back(storeIndex+1);
			}
			else if (numbers[i]>diffValue)
			{
				diffValue = target - numbers[--storeIndex];
				--i;
			}

		}
		return _result;
	}
	int getLessNumIndex(vector<int> &numbers, int target)
	{
		int length = 0;
		auto r = lower_bound(numbers.begin(), numbers.end(), target);
		if (r != numbers.end() && *r == target)
			length = distance(numbers.begin(), r);
		else
			length = numbers.size();
		return length;
	}

private:
	vector<int> _result;
};
int main(int argc, char **argv)
{
	
	Solution s;
	vector<int> test(100000,0);
	clock_t start = clock();
	vector<int> result=s.twoSum1(test, 0);
	clock_t end = clock();
	std::cout << "runtime is " << end - start << std::endl;
	for (auto b : result)
		std::cout << b << std::endl;
	return 0;
}