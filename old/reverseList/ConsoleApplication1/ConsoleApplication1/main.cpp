//单链表的动态创建，查找，遍历，删除，插入，添加，排序

#include<iostream>
#include"node.h"
#include<vector>
#include<windows.h>
using namespace std;
/*
typedef struct node //定义一个结构体，在c++中也是一个类
{
	int val;
	struct node* pNext;
}NODE,*PNODE;
*/
//NODE == struct node  定义一个新的接点
//PNODE == struct node* 定义一个指向这个接点的指针

class MyList //创建一个类 
{
//private:
	//PNODE pHead;//struct node* pHead
	
public:
	PNODE pHead;
	MyList()   //构造函数，构造一个空链表头指针
	{
		this->pHead = NULL;
	}
	
	~MyList()  //析构函数
	{
		while(this->pHead!=NULL)
		{
			PNODE pTemp = pHead->pNext;
			delete pHead;
			pHead = pTemp;
		}
	}
	
	void Init()   //初始化链表
	{
		int a;
		char ans;
		
		PNODE pTail,pNew;
		
		do
		{		
			cout<<"请输入一个节点值：";
			cin>>a;
			
			if(pHead == NULL)//判断链表中是否有元素（是否是空链表）
			{
				pHead = new NODE;
				pHead->val = a;
				pHead->pNext = NULL;
				
				pTail = pHead;
			}	
			else
			{	
				pTail = pHead;
				while(pTail->pNext!=NULL)//把pTail移动到尾部
				{
				    pTail = pTail->pNext;
				}

				pNew = new NODE;//new一个新的接点来接受新输入的值
				pNew->val = a;
				pNew->pNext = NULL;

				pTail->pNext = pNew;
				pTail = pTail->pNext;
			}	
			
			cout<<"继续吗？(Y/N):  ";
			cin>>ans;
			
		}while(ans=='Y'||ans=='y');	
	}
	PNODE reverseList1(PNODE head)
	{
		PNODE prev=NULL;
		while(head!=NULL)
		{
			PNODE tmp=head->pNext;
			head->pNext=prev;
			prev=head;
			head=tmp;
		}
		return prev;
	}
	PNODE deleteDuplicates(PNODE head)
	{
		PNODE tmp=head;
		while(tmp->pNext!=NULL)
		{
			if(tmp->val==tmp->pNext->val)
			{
				tmp->pNext=tmp->pNext->pNext;
				
			}
			else
				tmp=tmp->pNext;
		}
		return head;
	}
	PNODE reverseList(PNODE head)
	{
		vector<int>a;
		PNODE pNew,pTail;
		if(head==NULL)
		{
			return NULL;
		}
		else
		{
			
			for(pTail=head;pTail!=NULL;pTail=pTail->pNext)
			{
					a.push_back(pTail->val);
					
			}
		}
		int size=a.size();
		for(int j=0;j<size/2;j++)
		{
			int temp=a[j];
			a[j]=a[size-j-1];
			a[size-j-1]=temp;
		}
		pNew=new NODE;
		PNODE temp=pNew;
		pNew->val=a[0];
		for(int j=1;j<size;j++){
		PNODE pTMP=new NODE;
		pNew->pNext=pTMP;
		pTMP->val=a[j];
		pNew=pTMP;
		pNew->pNext=NULL;

		}
		return temp;
	}
	void Add(int val) //向链表中追加值方法
	{
		if(pHead == NULL)
		{
			pHead = new NODE;
			pHead->val = val;
			pHead->pNext = NULL;
		}
		else
		{
			PNODE pTemp = pHead;
			while(pTemp->pNext!=NULL)
			{
				pTemp = pTemp->pNext;
			}

			PNODE pNew = new NODE;
			pNew->val = val;
			pNew->pNext = NULL;

			pTemp->pNext = pNew;
		}		
	}
	
	int DelAt(int k)   //删除链表中的元素的方法
	{
		PNODE p1,p2,pTemp;

		if(pHead == NULL)
		{
			return -1;
		}

		if(k<0 || k>this->GetNodeCnt()-1)
		{
			return -1;
		}

		if(this->GetNodeCnt() == 1)
		{
			delete pHead;
			pHead = NULL;
			return 0;
		}

		if(k==0)
		{
			pTemp = pHead;
			pHead = pTemp->pNext;
			delete pTemp;
			return 0;
		}

		if(k == this->GetNodeCnt()-1)
		{
			PNODE p,pTemp;

			p = pHead;
			while(p->pNext->pNext!=NULL)
			{
				p = p->pNext;
			}

			pTemp = p->pNext;

			p->pNext = NULL;
			delete pTemp;

			return 0;
		}

		p1 = pHead;
		int i=0;
		while(i<k-1)
		{
			p1 = p1->pNext;
			i++;
		}

		pTemp = p1->pNext;
		p2 = p1->pNext->pNext;

		p1->pNext = p2;
		delete pTemp;
		return 0;
	}
	
	int InsertAt(int val,int k)//向链表中插入元素，约定在k之前插入
	{
		PNODE p1,p2,pNew,pTemp;

		if(pHead == NULL)//链表为空
		{
			return -1;
		}

		if(k<0 || k>this->GetNodeCnt()-1)//k越界
		{
			return -1;
		}

		if(k==0)//在头节点之前插入
		{
			pTemp = pHead;

			pNew = new NODE;
			pNew->val = val;
			pNew->pNext = NULL;

			pHead = pNew;

			pNew->pNext = pTemp;
			
			return 0;
		}

		p1 = pHead;
		int i =0;
		while(i<k-1)
		{
			p1 = p1->pNext;
			i++;
		}

		p2 = p1->pNext;

		pNew = new NODE;
		pNew->val = val;
		pNew->pNext = NULL;

		p1->pNext = pNew;
		pNew->pNext = p2;

		return 0;

	}
	
	int Find(int val)  //按输入的值查找方法
	{
		int i=0;
		PNODE pTemp = pHead;
		while(pTemp != NULL)
		{
			if(pTemp->val == val)
			{
				return i;
			}
			pTemp = pTemp->pNext;
			i++;
		}
		return -1;
	}
	
	void Travel()  //遍历单链表中的元素
	{
		PNODE pTemp = this->pHead;

		while(pTemp!=NULL)
		{ 
			cout<<pTemp->val<<"  ";
			pTemp = pTemp->pNext;
		}
		cout<<endl;	
	}

	int GetNodeCnt()  //获取单链表中元素的个数
	{
		int cnt=0;
		PNODE pTemp = pHead;

		while(pTemp!=NULL)
		{
			cnt++;
			pTemp = pTemp->pNext;
		}

		return cnt;
	}
	
	void sort()  //把单链表中的元素排序
	{
		int n = this->GetNodeCnt();
		PNODE p1,p2;

		for(int i=0;i<n-1;i++)
		{
			p1 = pHead;

			for(int j=0;j<n-1-i;j++)
			{
				p2 = p1->pNext;

				if(p1->val < p2->val)
				{
					int k = p1->val;
					p1->val = p2->val;
					p2->val = k;
				}

				p1 = p1->pNext;
			}
		}
	}
};


//测试主函数

int main(int argc,char **argv)
{
	MyList list,list1,list2;
	

	for(int i=0;i<3;i++)
	{
		list.Add(i);
		list.Add(i);
	}
	list1.pHead=list.deleteDuplicates(list.pHead);
	list1.Travel();
	/*
	list.Travel();
	DWORD s=GetTickCount(); 
	list1.pHead=list.reverseList(list.pHead);
	list1.Travel();
	DWORD e=GetTickCount();
	cout<<"my method's time is "<<(e-s)<<"ms"<<endl;
	DWORD s1=GetTickCount();
	list2.pHead=list.reverseList1(list.pHead);
	list2.Travel();
	DWORD e1=GetTickCount();
	cout<<"new method's time is "<<(e1-s1)<<"ms"<<endl;
	*/
//	list.sort();

//	list.Travel();
	return 0;	
}

