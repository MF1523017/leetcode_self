// MergeTwoSortedLists.cpp : 定义控制台应用程序的入口点。
//Merge two sorted linked lists and return it as a new list.The new list should be made by splicing together the nodes of the first two lists.
//

#include "stdafx.h"
#include<iostream>

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode nothing(INT_MIN);
		ListNode *result = &nothing;
		while (l1&&l2)
		{
			if (l1->val<l2->val)
			{
				result->next = l1;
				l1 = l1->next;
			}
			else
			{
				result->next = l2;
				l2 = l2->next;
			}
			result = result->next;
		}
		result->next = l1 ? l1 : l2;
		return nothing.next;
	}
};

int main()
{
    return 0;
}

