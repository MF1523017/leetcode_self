// ValidParentheses.cpp : 定义控制台应用程序的入口点。
/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.*/
//

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<string>
using std::string;
using std::stack;
class Solution {
public:
	bool isValid(string s) {
		if (s.empty())return false;
		stack<char> brackets;
		brackets.push(s[0]);
		for (int i = 1; i<s.size(); ++i)
		{
			if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			{
				brackets.push(s[i]);
			}
			else
			{
				if (brackets.empty())
					return false;
				char tmp = brackets.top();
				if ((s[i] == ')'&&tmp == '(') || (s[i] == '}'&&tmp == '{') || (s[i] == ']'&&tmp == '['))
				{
					brackets.pop();
				}
				else
					return false;
			}
		}
		if (brackets.empty())
			return true;
		return false;
	}
};
int main()
{
	string s("(])");
	Solution test;
	std::cout << test.isValid(s) << std::endl;
    return 0;
}

