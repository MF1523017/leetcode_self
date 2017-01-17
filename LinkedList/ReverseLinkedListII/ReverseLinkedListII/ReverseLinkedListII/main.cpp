//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
#include<iostream>
using std::cout;
using std::endl;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode preHead(0);
		preHead.next= head;
		ListNode *pre = &preHead;
		n -= m;
		while (--m)
		{
			pre = pre->next;
		}
		ListNode *startPtr = pre->next;
		while (n--)
		{
			ListNode *p = startPtr->next;
			startPtr->next = p->next;
			p->next = pre->next;
			pre->next = p;
		}
		return preHead.next;
	}
};
int main(int argc, char **argv)
{
	ListNode *head = new ListNode(0);
	ListNode *tmp = head;
	for (int i = 1; i < 5; ++i)
	{
		tmp->next=new ListNode(i);
		tmp = tmp->next;
	}
	tmp->next = nullptr;
	Solution test;
	test.reverseBetween(head, 4, 4);
	tmp = head;
	while (tmp)
	{
		cout << tmp->val;
		tmp = tmp->next;
	}
	return 0;
}