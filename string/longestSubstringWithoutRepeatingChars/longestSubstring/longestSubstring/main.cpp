#include<iostream>
#include<string>
using std::string;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0;//������¼���ַ����ʼ��index
		int length = 0;//������¼���ַ����ĳ���
		string substr("");
		for (int i = 0; i < s.size(); ++i)
		{
			std::size_t foundresult = substr.find(s[i]);//���µ��ַ���û�������ַ����г���;
			std::cout << foundresult << std::endl;
			if(foundresult!=string::npos)//�������
			{
				if ( i-start>=length) {//���ַ����ĳ��ȴ��ڵ��ڼ�¼�е����ַ�������
					length =i-start;//�������ַ�����󳤶�
				}
				start += foundresult;//������ʼλ��
				start += 1;
				substr = s.substr(start, substr.size() - foundresult);//�������ַ���
				std::cout << substr << std::endl;
			}
			else//������µ��ַ�û�������ַ����г���;�������ַ���
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