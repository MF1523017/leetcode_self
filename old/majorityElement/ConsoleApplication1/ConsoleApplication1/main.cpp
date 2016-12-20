#include<iostream>
#include<vector>
#include<windows.h>
#include<unordered_map>
using namespace std;
int majorityElement(vector<int>& nums) {
       /*
       unordered_map<int ,int>bk;
       for (int i=0;i<nums.size();i++)
       {
            bk[nums[i]]++;
            if(bk[nums[i]]>nums.size()/2)
            {
                return nums[i];
            }
       }
       */
       int me=0;
       int count=0;
       for(int i=0;i<nums.size();i++)
       {
           if(count==0)
           {
               me=nums[i];
               count=1;
           }
           else
           {
               if(nums[i]==me)
               {
                   count++;
               }
               else
               {
                   count--;
               }
           }
           
       }
       return me;
    }
int majorityElement1(vector<int>& nums) {
       unordered_map<int ,int>bk;
       for (int i=0;i<nums.size();i++)
       {
            bk[nums[i]]++;
            if(bk[nums[i]]>nums.size()/2)
            {
                return nums[i];
            }
       }
}
int main(int argc,char ** argv)
{
	vector<int>a(1000,1);
	for(int i=0;i<1000;i++)
	{
		a.push_back(i);
	}
	int mje=majorityElement(a);	
	cout<<mje<<endl;
	int mje1=majorityElement1(a);
	cout<<mje1<<endl;
	DWORD start_time=GetTickCount();
	mje=majorityElement(a);	
	DWORD end_time=GetTickCount();
	cout<<"delete method run time is "<<(end_time-start_time)<<"ms"<<endl;
	DWORD start_time1=GetTickCount();
	mje=majorityElement1(a);	
	DWORD end_time1=GetTickCount();
	cout<<"hash method run time is "<<(end_time1-start_time1)<<"ms"<<endl;
	return 0;

	
}