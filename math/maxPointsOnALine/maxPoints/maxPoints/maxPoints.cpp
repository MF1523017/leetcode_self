// maxPoints.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
using std::vector;
using std::map;
using std::pair;
using std::make_pair;
// Definition for a point.
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };
 //霍夫变换，这里不能使用斜率来作为key，因为，double 类型精度问题
 //这里我们使用分数来代替double，
class Solution {
public:
	int maxPoints(vector<Point>& points) {
		if (points.empty())
			return 0;
		if (points.size() == 1)
			return 1;
		int result = 0;
		for (vector<Point>::iterator X = points.begin(); X != points.end(); ++X)
		{
			map<pair<int, int>, int> slope;
			int samePoint = 1;
			int vertical = 1;
			for (vector<Point>::iterator Y = X + 1; Y != points.end(); ++Y)
			{
				if (X->x == Y->x&&X->y == Y->y)
					++samePoint;
				else {
					if (Y->x == X->x)
						++vertical;
					else {
						int a = Y->y - X->y;
						int b = Y->x - X->x;
						int gcd = GCD(a, b);
						a /= gcd;
						b /= gcd;
						slope[make_pair(a, b)]++;
					}
				}

				int maxPointNum = 0;
				for (auto item : slope)
				{
					if (item.second > maxPointNum)
						maxPointNum = item.second;
				}
				maxPointNum = std::max(maxPointNum + samePoint, vertical);
				result = std::max(result, maxPointNum);
			}
		}
			return result;
		}
private:
	int GCD(int a, int b) {
		if (b == 0) return a;
		else return GCD(b, a%b);
	}
};

int main()
{
	vector<Point> test;
	test.push_back(Point(0, 0));
	test.push_back(Point(94911151, 94911150));
	test.push_back(Point(94911152, 94911151));
	Solution s;
	std::cout<<s.maxPoints(test)<<std::endl;
    return 0;
}

