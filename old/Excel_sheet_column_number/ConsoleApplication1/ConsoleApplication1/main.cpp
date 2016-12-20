#include<iostream>
#include<windows.h>
#include<string>
using namespace std;
int titleToNumber(string s)
{
		int size=s.size();
        int nums=0;
        for (int i=0;i<size;i++)
        {
            nums+=(s[i]-'A'+1)*pow(26,size-1-i);
            
        }
        return nums;
}
int titleToNumber1(string s)
{
		int size=s.size();
        int nums=0;
        for (int i=0;i<size;i++)
        {
            nums=nums*26+(s[i]-'A'+1);
            
        }
        return nums;
}
int main(int argc,char **argv)
{

	DWORD start_time=GetTickCount();
	cout<<titleToNumber1("AF")<<endl;
	DWORD end_time=GetTickCount();
	cout<<"run time is "<<(end_time-start_time)<<"ms"<<endl;
	DWORD start_time1=GetTickCount();
	cout<<titleToNumber1("AF")<<endl;
	DWORD end_time1=GetTickCount();
	cout<<"run1 time is "<<(end_time1-start_time1)<<"ms"<<endl;
	return 0;
}