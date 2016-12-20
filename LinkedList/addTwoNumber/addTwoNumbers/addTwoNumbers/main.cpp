#include"list.h"
#include<iostream>
#include<vector>
using std::vector;
/**
* Definition for singly-linked list.
* struct Node {
*     int element;
*     Node *next;
*     Node(int x) : element(x), next(NULL) {}
* };
*/
class Solution {
public:
	Node* addTwoNumbers(Node* l1, Node* l2) {
		Node *tmpl1 = l1->next;//有头节点的情况
		Node *tmpl2 = l2->next;

		int tmpValue = 0;
		while (tmpl1 && tmpl2)
		{
			tmpValue = addResult(tmpl1->element, tmpl2->element, tmpValue);
			tmpl1 = tmpl1->next;
			tmpl2 = tmpl2->next;
		}

		while (tmpl1)
		{
			tmpValue = addResult(tmpl1->element, 0, tmpValue);
			tmpl1 = tmpl1->next;
		}
		while (tmpl2)
		{
			tmpValue = addResult(0, tmpl2->element, tmpValue);
			tmpl2 = tmpl2->next;
		}
		if (tmpValue != 0)
			_addResult.push_back(tmpValue);
		Node *result = new Node;
		result->element = _addResult[0];
		result->next = nullptr;
		Node *tmp = result;
		for (int i = 1; i<_addResult.size(); ++i)
		{
			tmp = insert(tmp, _addResult[i]);
		}
		return result;
	}
	Node* insert(Node * L, int v)
	{
		Node *tmp = new Node;
		tmp->element = v;
		tmp->next = nullptr;
		L->next = tmp;
		return tmp;
	}
	int addResult(int a, int b, int tmp)
	{
		int sum = a + b + tmp;
		_addResult.push_back(sum % 10);
		return sum / 10;
	}
private:
	vector<int> _addResult;
};
int main(int argc, char **argv)
{
	List l1 = CreateList();
	List l2 = CreateList();
	for (int i = 0; i < 10; ++i)
	{
		ListAppend(i, l1);
		ListAppend(10 - i, l2);
	}
	Solution s;
	List result=s.addTwoNumbers(l1, l2);
	printList(result);
	return 0;
}