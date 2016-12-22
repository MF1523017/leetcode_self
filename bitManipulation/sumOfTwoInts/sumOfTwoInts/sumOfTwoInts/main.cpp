#include<iostream>
#include<ctime>
class Solution {
public:
	int getSum1(int a, int b) {
		if (a == 0)
			return b;
		if (b == 0)
			return a;

		int sum = 0;
		int mask = 1;
		int  c = 0;

		while (mask != 0)
		{
			int m1 = (a & mask) != 0 ? 1 : 0;
			int m2 = (b & mask) != 0 ? 1 : 0;

			if (m1 == 1 && m2 == 1)
			{
				if (c == 1)
					sum |= mask;

				c = 1;
			}
			else if ((m1 ^ m2) == 1)
			{
				if (c == 1)
					c = 1;
				else
					sum |= mask;
			}
			else
			{
				if (c == 1)
				{
					sum |= mask;
					c = 0;
				}
			}

			mask <<= 1;
		}

		return sum;
	}
	//只实现了正数的情况
	int getSum(int a, int b) {
		int result;
		if (a >= 0 && b >= 0)
			result = positiveNums(a, b);
		if (a < 0 && b < 0)
			result=-positiveNums(-a, -b);
		return result;
	}
	int positiveNums(int a, int b)
	{
		int result = 0;
		int i = 0;
		int high = 0;
		int bita = 0;
		int bitb = 0;
		int currentResult = 0;
		while (a || b)
		{
			bita = a & 1;
			bitb = b & 1;
			if (high == 0)
			{
				if (bita&&bitb)
				{
					high = 1;
					currentResult = 0;
				}
				else if (bita || bitb)
				{
					high = 0;
					currentResult = 1;
				}
				else
				{
					high = 0;
					currentResult = 0;
				}
			}
			else
			{
				if (bita&&bitb)
				{
					high = 1;
					currentResult = 1;
				}
				else if (bita || bitb)
				{
					high = 1;
					currentResult = 0;
				}
				else
				{
					high = 0;
					currentResult = 1;
				}
			}
			result = result | (currentResult << i);
			++i;
			a = a >> 1;
			b = b >> 1;
		}
		result = result | (high << i);
		return result;
		
	}
};
int main(int argc, char **argv)
{
	Solution s;
	int a = 5;
	
	clock_t start = clock();
	std::cout << s.getSum1(-1, -3) << std::endl;
	clock_t end = clock();
	std::cout << "time is " << static_cast<double>(end - start) << std::endl;
}