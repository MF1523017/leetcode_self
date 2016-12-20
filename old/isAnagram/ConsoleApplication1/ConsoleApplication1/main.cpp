#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<windows.h>
using namespace std;
bool isAnagram(string s,string t)
{
	if(s.size()!=t.size())
		return false;
	else{
	unordered_map<char,int>ss;
	unordered_map<char,int>tt;
	
	for(int i=0;i<s.size();i++)
	{
		ss[s[i]]++;
		tt[t[i]]++;
	}
	
	if(ss==tt)
	{
		return true;
	}
	else
		return false;


	}
}
bool isAnagram1(string s,string t)
{
		std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        if (s==t)
        {
            return true;
        }
        else
        {
            return false;
        }

}
bool isAnagram2(string s,string t)
{
	if(s.size()!=t.size())
		return false;
	else
	{
		int a[26]={0};
		for (int i=0;i<s.size();i++)
		{
			a[s[i]-'a']++;
		}
		for(int i=0;i<t.size();i++)
		{
			--a[t[i]-'a'];
			if(a[t[i]-'a']<0)
				return false;
		}
		return true;
	}
}
int main(int argc,char **argv)
{
	string a="abcdefghijklmopqrtttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttstuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvwxyzzzz";
	string b="zzzzyxwvuttttttttttttttttttttttttttttssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssstttttttttsrqpomlkjihgfedcba";
	DWORD start_time=GetTickCount();
	cout<<isAnagram(a,b)<<endl;
	DWORD end_time=GetTickCount();
	cout<<"hash_table time is "<<(end_time-start_time)<<"ms"<<endl;
	DWORD start_time1=GetTickCount();
	cout<<isAnagram1(a,b)<<endl;
	DWORD end_time1=GetTickCount();
	cout<<"sort time is "<<(end_time1-start_time1)<<"ms"<<endl;
	DWORD start_time2=GetTickCount();
	cout<<isAnagram2(a,b)<<endl;
	DWORD end_time2=GetTickCount();
	cout<<"new_hash_table time is "<<(end_time2-start_time2)<<"ms"<<endl;
	return 0;

}