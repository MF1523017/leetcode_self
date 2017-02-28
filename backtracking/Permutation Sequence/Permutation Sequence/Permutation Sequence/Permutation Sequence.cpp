// Permutation Sequence.cpp : 定义控制台应用程序的入口点。
 /*The set[1, 2, 3, …, n] contains a total of n!unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence(ie, for n = 3) :

	"123"
	"132"
	"213"
	"231"
	"312"
	"321"
	Given n and k, return the kth permutation sequence.*/
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using std::string;
using std::vector;
using std::to_string;
using std::swap;
class Solution {
public:
	string getPermutation1(int n, int k) {
		int i, j, f = 1;
		// left part of s is partially formed permutation, right part is the leftover chars.
		string s(n, '0');
		for (i = 1; i <= n; i++) {
			f *= i;
			s[i - 1] += i; // make s become 1234...n
		}
		for (i = 0, k--; i<n; i++) {
			f /= n - i;
			j = i + k / f; // calculate index of char to put at s[i]
			char c = s[j];
			// remove c by shifting to cover up (adjust the right part).
			for (; j>i; j--)
				s[j] = s[j - 1];
			k %= f;
			s[i] = c;
		}
		return s;
	}
	void helper(vector<string> &v, string s, int begin)
	{
		if (begin == s.size())
			v.push_back(s);
		for (int i = begin; i<s.size(); ++i)
		{
			swap(s[begin], s[i]);
			helper(v, s, begin + 1);
			swap(s[begin], s[i]);
		}
	}
	string getPermutation(int n, int k) {
		string s("");
		for (int i = 1; i <= n; ++i)
		{
			s += to_string(i);
		}
		vector<string> res;
		helper(res, s, 0);
		return res[k];
	}
};
int main()
{
	Solution test;
	string res=test.getPermutation1(3, 5);
    return 0;
}

