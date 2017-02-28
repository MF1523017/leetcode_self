// longestPalindromic.cpp : 定义控制台应用程序的入口点。
//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example:
//
//Input: "babad"
//
//	Output : "bab"
//
//	Note : "aba" is also a valid answer.
//	Example :
//
//	Input : "cbbd"
//
//	Output : "bb"
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
using std::string;
using std::distance;
class Solution {
public:
	string longestPalindrome1(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.size();) {
			if (s.size() - i <= max_len / 2) break;
			int j = i, k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
			{	++k; 
				--j; 
			} // Expand.从中间字母向两边扩展，直至得到不同的字母，得到的就是回文的长度
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
	}
	string longestPalindrome(string s) {
		string result;
		for (auto b = s.begin(); b<s.end();)
		{
			for (int i = result.size(); i<=distance(b, s.end()); ++i) {
				string tmp(b, b + i);
				if (isPalindromic(tmp) && tmp.size() > result.size())
					result = tmp;
			}
			if (distance(b, s.end()) <= result.size() / 2)
				break;
			b += result.size();
		}
		return result;
	}
private:
	bool isPalindromic(string s)
	{
		return s == string(s.rbegin(), s.rend());
	}
};
int main(int argc,char **argv)
{
	Solution test;
	clock_t start = clock();
	std::cout<<test.longestPalindrome1("ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy")<<std::endl;
	clock_t end = clock();
	std::cout << end - start << std::endl;
	return 0;
}

