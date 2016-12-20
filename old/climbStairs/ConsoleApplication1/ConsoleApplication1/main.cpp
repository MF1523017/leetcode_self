#include<iostream>
#include<windows.h>
using namespace std;
int combinatorial_num(int ,int);
 int climbStairs(int n) {
        int res=0;
        if(n%2==0)
        {
            for(int i=n/2;i<=n;i++)
            {
                res+=combinatorial_num(i,n-i);
            }
        }
        else
        {
            for(int j=n/2+1;j<=n;j++)
            {
                res+=combinatorial_num(j,n-j);
            }
        }
        return res;
       
        
    }
    int combinatorial_num(int n,int m)
    {
        if(m==0)
        {
            return 1;
        }
        else{
			if(m>n/2)
			{
				m=n-m;
			}
        int temp=m;
		long long res=1;
        for(int i=n-m+1;i<=n;i++)
        {
			
            res*=i;
			if(temp>0&&res%temp==0)
			{
				res=res/temp;
				temp=temp-1;
			}
        }
		
        long long div=1;
        if(temp>0){
		for(int j=1;j<=temp;j++)
        {
            div*=j;
        }
		}
        return res/div;
        }
    }
int	climbStairs1(int n)
{
	if(n<4)return n;
	int a=1;
	int b=2;
	int c=5;
	for(int i=5;i<=n;i++)
	{
		a=c;
		c=a+b;
		b=a;
	}
	return c;
}
	int main(int argc,char **argv)
	{
		cout<<sizeof(long long)<<endl;
		//cout<<combinatorial_num(30,14)<<endl;
		DWORD s=GetTickCount();
	cout<<climbStairs(45)<<endl;
	DWORD e=GetTickCount();
	cout<<"my method'time is:"<<(e-s)<<"ms"<<endl;

		DWORD s1=GetTickCount();
	cout<<climbStairs1(45)<<endl;
	DWORD e1=GetTickCount();
	cout<<"dong_tai method'time is:"<<(e1-s1)<<"ms"<<endl;
	return 0;
	
	}