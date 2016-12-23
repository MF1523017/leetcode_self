#include<iostream>
#include<cmath>
#include<ctime>
#include<vector>
//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
//
//Example1:
//
//a = 2
//b = [3]
//
//Result : 8
//	Example2 :
//
//	a = 2
//	b = [1, 0]
//
//	Result : 1024


using std::cout;
using std::endl;
using std::vector;
class Solution {
	/*One knowledge : ab % k = (a%k)(b%k) % k
		Since the power here is an array, we'd better handle it digit by digit.
		One observation :
	a ^ 1234567 % k = (a ^ 1234560 % k) * (a ^ 7 % k) % k = (a ^ 123456 % k) ^ 10 % k * (a ^ 7 % k) % k
		Looks complicated ? Let me put it other way :
	Suppose f(a, b) calculates a^b % k; Then translate above formula to using f :
	f(a, 1234567) = f(a, 1234560) * f(a, 7) % k = f(f(a, 123456), 10) * f(a, 7) % k;
	Implementation of this idea:*/
	const int base = 1337;
	int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
	{
		a %= base;
		int result = 1;
		for (int i = 0; i < k; ++i)
			result = (result * a) % base;
		return result;
	}
public:
	int superPow1(int a, vector<int>& b) {
		if (b.empty()) return 1;
		int last_digit = b.back();
		b.pop_back();
		return powmod(superPow1(a, b), 10) * powmod(a, last_digit) % base;
	}
	//直接法，对于相对比较小的b还可以
	int superPow(int a, vector<int>& b) {
		int realb = getB(b);
		long long tmpA = a;
		long long tmpaa = a;
		int result=0;
		for (int i = 0; i < realb-1; ++i)
		{
			if (tmpA % 1337 == 0)
				break;
			else
			{
				tmpA = tmpA % 1337;
			}
			tmpA *= tmpaa;
		}
		result = tmpA % 1337;
		return result;
	}
	int getB(vector<int>&b)
	{
		int realb = 0;
		int size = b.size();
		for (int i = 0; i<size; ++i)
		{
			realb += b[i] * static_cast<int>(pow(static_cast<double>(10), static_cast<double>(size - i - 1)));
		}
		return realb;
	}
};
int main(int argc, char **argv)
{
	clock_t start = clock();
	vector<int> test({ 2,0,0 });
	Solution s;
	cout<<s.superPow1(2147483647, test)<<endl;
	clock_t end = clock();
	cout << "run time is " << (end - start) << endl;
	
	return 0;
}