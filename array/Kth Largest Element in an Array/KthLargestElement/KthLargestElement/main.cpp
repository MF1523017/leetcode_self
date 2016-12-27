#include<iostream>
#include<set>
#include<vector>
#include<ctime>
#include<queue>
using std::vector;
using std::multiset;
using std::priority_queue;
struct  mycmp
{
	bool operator()(const int &a, const int &b)
	{
		return a > b;//从小到大保存
	}
};
class Solution {
public:
	int findKthLargest1(vector<int>& nums, int k) {
		priority_queue<int,vector<int>,mycmp> npq;
		for (auto n : nums)
		{
			npq.push(n);
			if (npq.size()>k)
				npq.pop();
		}
		return npq.top();
	}
	int findKthLargest(vector<int>& nums, int k) {
		multiset<int> nset;
		for (auto n : nums)
		{
			nset.insert(n);
			if (nset.size()>k)
				nset.erase(nset.begin());
		}
		return *nset.begin();
	}
};
int main(int argc, char **argv)
{
	Solution s;
	vector<int> test(1000, 2);
	clock_t start = clock();
	std::cout << s.findKthLargest1(test,100) << std::endl;
	clock_t end = clock();
	std::cout << "time is " << static_cast<double>(end - start) << std::endl;
}