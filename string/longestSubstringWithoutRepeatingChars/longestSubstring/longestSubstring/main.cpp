#include<iostream>
#include<string>
using std::string;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0;//用来记录子字符串最开始的index
		int length = 0;//用来记录子字符串的长度
		string substr("");
		for (int i = 0; i < s.size(); ++i)
		{
			std::size_t foundresult = substr.find(s[i]);//最新的字符有没有在子字符串中出现;
			std::cout << foundresult << std::endl;
			if(foundresult!=string::npos)//如果出现
			{
				if ( i-start>=length) {//子字符串的长度大于等于记录中的子字符串长度
					length =i-start;//更新子字符串最大长度
				}
				start += foundresult;//更新起始位置
				start += 1;
				substr = s.substr(start, substr.size() - foundresult);//更新子字符串
				std::cout << substr << std::endl;
			}
			else//如果最新的字符没有在子字符串中出现;更新子字符串
				substr += s[i];
			
		}
		if (substr.size()>length)
			length = substr.size();
		return length;
	}
};
int main(int argc, char **argv)
{
	Solution s;
	string test("fbojelwjgercer");
	std::cout<<s.lengthOfLongestSubstring(test)<<std::endl;
	return 0;
}