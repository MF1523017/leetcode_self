#include<iostream>
#include<string>
using std::string;
//Given two strings s and t which consist of only lowercase letters.
//
//string t is generated by random shuffling string s and then add one more letter at a random position.
//
//find the letter that was added in t.
//Example:
//
//Input:

//s = "abcd"
//t = "abcde"
//
//Output :
//	e
//
//	Explanation :
//'e' is the letter that was added.
class Solution {
public:
	char findTheDifference1(string s, string t)
	{
		//s和t只有一个字符是不成对的，成对的部分最终都将被异或成0，任何数与0异或都是该数值，所以最后就是得到的字符
		char r = 0;
		for (char c : s) 
			r ^= c;
		for (char c : t) 
			r ^= c;
		return r;
	
	}
	//直接解法
	char findTheDifference(string s, string t) {
		int smap[26];
		int tmap[26];
		char result;

		for (int i = 0; i<26; ++i)
		{
			smap[i] = 0;
			tmap[i] = 0;
		}
		for (auto c : s)
		{
			++smap[c - 'a'];
		}
		for (auto c : t)
		{
			++tmap[c - 'a'];
		}

		for (int i = 0; i<26; ++i)
		{
			if (smap[i] != tmap[i])
			{
				result = i + 'a';
				break;
			}
		}

		return result;
	}
};
int main(int argc, char **argv)
{
	Solution s;
	string s1("hello");
	string s2("heello");
	std::cout << s.findTheDifference1(s1, s2)<<std::endl;
	return 0;
}