#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<ctime>
using std::set;
using std::vector;

class Solution {
public:
	Solution() :_max(0), _second(0), _third(0) {}
	int thirdMax1(vector<int>&nums)
	{
		set<int> numset;
		for (auto n : nums)
		{
			numset.insert(n);
			if (numset.size() > 3)
				numset.erase(*numset.begin());
		}
		return numset.size() == 3 ? *numset.begin() : *numset.rbegin();
	}
	//很暴力的解法，
	int thirdMax(vector<int>& nums) {
		auto b=std::max_element(nums.begin(), nums.end());
		_max = *b;
		nums.erase(b);
		while (true)
		{
			b = std::max_element(nums.begin(), nums.end());
			if (*b == _max)
				nums.erase(b);
			else {
				_second = *b;
				break;
			}
			if (nums.empty())
				return _max;
		}
		while (true)
		{
			b = std::max_element(nums.begin(), nums.end());
			if (*b ==_second)
				nums.erase(b);
			else {
				_third = *b;
				break;
			}
			if (nums.empty())
				return _max;
		}
		return _third;
	}
private:
	
	int _max;
	int _second;
	int _third;
};
int main(int argc, char **argv)
{
	Solution s;
	vector<int> test(10000,1);
	clock_t start = clock();//单位是毫秒
	std::cout<<s.thirdMax1(test)<<std::endl;
	clock_t end = clock();
	std::cout << "run time is " << static_cast<double>(end - start) << std::endl;
	return 0;
}