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
	//�����ⷨ
	vector<int> twoSum1(vector<int>& nums, int target) {
		target=lessTarget(nums, target);
		for (int i = 0; i < _lessTarget.size(); ++i)
		{
			for (int j = i + 1; j < _lessTarget.size(); ++j)
			{
				if (_lessTarget[i] + _lessTarget[j] == target)
				{
					//Ѱ�ҷ���������ֵ���ڵ�index
					auto b = find(nums.begin(), nums.end(), _lessTarget[i]);
					if (b != nums.end())
						_result.push_back(distance(nums.begin(), b));//distance������������������֮��ľ���
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
		for (vector<int>::iterator b= nums.begin();b!=nums.end();++b)//���ﲻ��ʹ��auto��autoû���ı�nums�����ֵ������
			*b -= _minNum;
	}
	int lessTarget(vector<int>& nums, int target)
	{
		//�ҵ���Сֵ
		_minNum = *(min_element(nums.begin(), nums.end()));
		//�����Сֵ<0�������е�Ԫ�����������㣬Ŀ��ֵ��������Ϊ��������ֵ�ĺ�
		if (_minNum < 0) {
			addMin(nums);
			target -= 2*_minNum;
		}
		//�ҵ���Ŀ��ֵС�����֣�ѭ��һ����С�����飬ʱ���ӿ죡
		for (auto n : nums)
		{
			if (n <= target)
				_lessTarget.push_back(n);
		}
		return target;
	}
	//��ӡ����
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