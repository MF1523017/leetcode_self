// lengthLastWord.cpp : 定义控制台应用程序的入口点。
//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	For example,
//	Given s = "Hello World",
//	return 5.
//

#include "stdafx.h"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using std::vector;
using std::string;
using std::istringstream;
class Solution {
public:
	int lengthOfLastWord(string s) {
		istringstream ss(s);
		string tmp;
		vector<string> vs;
		while (ss >> tmp)
		{
			vs.push_back(tmp);
		}
		return tmp.size();
	}
};
int main()
{
	string s("aa");
	Solution test;
	std::cout<<test.lengthOfLastWord(s)<<std::endl;
    return 0;
}

