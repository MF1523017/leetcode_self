#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;
unordered_map<int ,int >result;

bool isHappy1(int n)
{
	
	if(n==1)
		return true;
	int t=0;
	while(n)
	{
		t=t+(n%10)*(n%10);
        n=n/10;	
	}
	if(result.empty())
	{
		result[1]++;
	}
	else
	{
		if(t==1)
			return true;
		if(result.find(t)!=result.end())
		{
			return false;
		}
	}
	++result[t];
	return isHappy1(t);

}
bool isHappy(int n)
{
	if (n==1)
	{
		return true;
	}
	else{
	unordered_map<int ,int>result_count;
	int t=0;
	++result_count[1];
	while(1){
		
    while(n)
	{
		 t=t+(n%10)*(n%10);
         n=n/10;
	}
	if(t==1)
		return true;
	
	if(result_count.find(t)!=result_count.end())
	{
		return false;
	}

	++result_count[t];
	n=t;
	t=0;
	}
	}
}
int main(int argc,char **argv)
{
	for(int i=0;i<1000;i++)
	{
		if(isHappy(i))
		cout<<i<<endl;
	}
	cout<<isHappy(7)<<endl;
	cout<<isHappy1(7)<<endl;
	return 0;
}