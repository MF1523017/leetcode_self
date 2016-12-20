#include<iostream>
#include<windows.h>
#include<algorithm>
using namespace std;
bool isPrime(int n)
    {
        if(n<4)
        return true;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
        
    }
bool isUgly1(int num) {
        while(num>=2){
      if(num%2==0)num=num/2;
      else if(num%3==0)num=num/3;
      else if(num%5==0)num=num/5;
       else return false;
        }
        return num==1;
    }
bool isUgly(int num){
 if(num<7)
        return true;
        else{
            /*
        int flag=0;
        if(num%2==0 || num %3==0 ||num%5==0)
        {
            flag++;
        }
        */
        for(int i=7;i<=num;i++)
        {
            if(isPrime(i)&&num%i==0)
            {
                return false;
            }
        }
        return true;
    }
}
  int main(int argc,char **argv)
  {
	  cout<<isUgly1(937351770)<<endl;
	//DWORD s=GetTickCount();
	//cout<<isUgly(937351770)<<endl;
	//DWORD e=GetTickCount();
	//cout<<"time is "<<(e-s)<<"ms"<<endl;
  }
