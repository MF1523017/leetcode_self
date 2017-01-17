//Given a non - empty string s and a dictionary wordDict containing a list of non - empty words, 
//determine if s can be segmented into a space - separated sequence of one or more dictionary words.
//You may assume the dictionary does not contain duplicate words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".

#include<iostream>
#include<vector>
#include<string>
#include<map>
using std::string;
using std::vector;
using std::map;
using std::find;
//We use a boolean vector dp[].dp[i] is set to true if a valid word(word sequence) ends there.
//The optimization is to look from current position i back and only substring and 
//do dictionary look up in case the preceding position j with dp[j] == true is found.
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (wordDict.empty())return false;
		vector<bool>dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (dp[j])
				{
					string word = s.substr(j, i - j);
					if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
					{
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
};
int main(int argc, char **argv)
{
	string s("abcd");
	vector<string> dict({ "a","abc","b","cd" });
	Solution test;
	std::cout << test.wordBreak(s, dict)<<std::endl;;
	return 0;
}