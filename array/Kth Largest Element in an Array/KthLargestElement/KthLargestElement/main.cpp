#include<iostream>
#include<set>
#include<vector>
#include<ctime>
using std::vector;
using std::multiset;
class Solution {
public:
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
	std::cout << s.findKthLargest(test,100) << std::endl;
	clock_t end = clock();
	std::cout << "time is " << static_cast<double>(end - start) << std::endl;
}