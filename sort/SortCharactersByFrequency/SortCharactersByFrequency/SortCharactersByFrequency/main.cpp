//Given a string, sort it in decreasing order based on the frequency of characters.
//Example 1:
//
//Input:
//"tree"
//
//Output :
//	"eert"
//
//	Explanation :
//	'e' appears twice while 'r' and 't' both appear once.
//	So 'e' must appear before both 'r' and 't'.Therefore "eetr" is also a valid answer.
//	Example 2 :
//
//	Input :
//	"cccaaa"
//
//	Output :
//	"cccaaa"
//
//	Explanation :
//	Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
//	Note that "cacaca" is incorrect, as the same characters must be together.
//	Example 3 :
//
//	Input :
//	"Aabb"
//
//	Output :
//	"bbAa"
//
//	Explanation :
//	"bbaA" is also a valid answer, but "Aabb" is incorrect.
//	Note that 'A' and 'a' are treated as two different characters.

#include<iostream>
#include<utility>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using std::string;
using std::pair;
using std::sort;
using std::unordered_map;
using std::vector;
struct sortSecond
{
	bool operator ()(pair<char, int> &lhs, pair<char, int> &rhs)
	{
		return lhs.second>rhs.second;
	}
}myObject;
class Solution {
public:
	string frequencySort1(string s) {
		unordered_map<char, int> freq;
		vector<string> bucket(s.size() + 1, "");
		string res;
		//count frequency of each character
		for (char c : s) freq[c]++;
		//put character into frequency bucket
		for (auto& it : freq) {
			bucket[it.second].append(it.second, it.first);
		}
		//form descending sorted string
		for (int i = s.size(); i>0; i--) {
			if (!bucket[i].empty())
				res.append(bucket[i]);
		}
		return res;
	}
	void build(string s)
	{
		for (auto c : s)
			++_charCount[c];
		for (auto v : _charCount)
			_forSort.push_back(v);
	}
	string frequencySort(string s) {
		build(s);
		sort(_forSort.begin(), _forSort.end(), myObject);
		string result;
		for (auto v : _forSort)
		{
			for (int i = 0; i<v.second; ++i)
				result += v.first;
		}
		return result;
	}
private:
	unordered_map<char, int> _charCount;
	vector<pair<char, int>> _forSort;
};

int main(int argc, char **argv)
{
	string s("aabcddd");
	Solution test;
	std::cout << test.frequencySort1(s) << std::endl;
	return 0;
}