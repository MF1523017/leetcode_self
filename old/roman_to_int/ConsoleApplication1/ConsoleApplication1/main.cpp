#include<iostream>
#include<string>
using namespace std;
//enum roman{I=1,V=5,X=10,L=50,C=100,D=500,M=1000};
int char_to_num(char a)
{
	switch (a)
	{
	case 'M':
		return 1000;
	case 'D':
		return 500;
	case 'C':
		return 100;
	case 'L':
		return 50;
	case 'X':
		return 10;
	case 'V':
		return 5;
	case 'I':
		return 1;
	default:
		cout<<"the roman is wrong\n";
		break;
	}

}
int roman_to_int(string s)
{
	int roman_num=char_to_num(s[0]);	
		for(int i=1;i<s.size();i++)
		{
		    if(char_to_num(s[i-1])<char_to_num(s[i]))
			{
				roman_num=roman_num-2*char_to_num(s[i-1])+char_to_num(s[i]);
			}
			else{
			roman_num=roman_num+char_to_num(s[i]);
			}

		}
		
		return roman_num;
	
}

int main(int argc,char**argv)
{
	string test="MDCLVXVI";
	cout<<roman_to_int(test)<<endl;
	return 0;
}