// Merge_Intervals.cpp : 定义控制台应用程序的入口点。
// Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using std::vector;
using std::sort;
using std::max;
using std::min;
struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};
bool mycmp(const Interval &lhs, const Interval &rhs)
{
	return lhs.start<rhs.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		if (intervals.size()<2)return intervals;
		sort(intervals.begin(), intervals.end(), mycmp);
		vector<Interval> res;
		vector<bool> foo(intervals.size(),true);
		for (int i = 0; i<intervals.size()-1; ++i)
		{
			if (intervals[i + 1].start <= intervals[i].end)
			{
				int left = min(intervals[i].start, intervals[i + 1].start);
				int right = max(intervals[i].end, intervals[i + 1].end);
				intervals[i+1]=Interval(left, right);
				foo[i]=false;
			}
		}
		for (int i = 0; i < intervals.size(); ++i)
		{
			if (foo[i] == true)
				res.push_back(intervals[i]);
		}
		return res;
	}
};

int main()
{
	vector<Interval> s;
	s.push_back(Interval(1, 4));
	s.push_back(Interval(5, 6));
	Solution test;
	test.merge(s);
    return 0;
}

