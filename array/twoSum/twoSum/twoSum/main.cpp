#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using std::map;
using std::vector;
using std::find;
using std::min_element;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> hash;
		for (int i = 0; i<nums.size(); ++i)
		{
			int nextNum = target - nums[i];
			if (hash.find(nextNum) != hash.end())
			{
				_result.push_back(hash.find(nextNum)->second);
				_result.push_back(i);
				break;
			}
			hash[nums[i]] = i;

		}

		return _result;
	}
	//暴力解法
	vector<int> twoSum1(vector<int>& nums, int target) {
		target=lessTarget(nums, target);
		for (int i = 0; i < _lessTarget.size(); ++i)
		{
			for (int j = i + 1; j < _lessTarget.size(); ++j)
			{
				if (_lessTarget[i] + _lessTarget[j] == target)
				{
					//寻找符合条件的值所在的index
					auto b = find(nums.begin(), nums.end(), _lessTarget[i]);
					if (b != nums.end())
						_result.push_back(distance(nums.begin(), b));//distance函数返回两个迭代器之间的距离
					nums.erase(b);
					b = find(nums.begin(), nums.end(), _lessTarget[j]);
					if (b != nums.end())
						_result.push_back(1 + distance(nums.begin(), b));
					break;
				}
			}
		}
		return _result;
	}
	void addMin(vector<int>& nums)
	{
		for (vector<int>::iterator b= nums.begin();b!=nums.end();++b)//这里不能使用auto，auto没法改变nums里面的值的内容
			*b -= _minNum;
	}
	int lessTarget(vector<int>& nums, int target)
	{
		//找到最小值
		_minNum = *(min_element(nums.begin(), nums.end()));
		//如果最小值<0，将所有的元素增加至非零，目标值翻倍，因为等于两个值的和
		if (_minNum < 0) {
			addMin(nums);
			target -= 2*_minNum;
		}
		//找到比目标值小的数字，循环一个较小的数组，时间会加快！
		for (auto n : nums)
		{
			if (n <= target)
				_lessTarget.push_back(n);
		}
		return target;
	}
	//打印数组
	void show()
	{
		for (auto b : _result)
			std::cout << b<<" ";
	}
 
private:
	vector<int> _lessTarget;
	vector<int> _result;
	int _minNum;
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> test({ -3,1,2,3 });
	s.twoSum(test, 0);
	s.show();
	return 0;
}