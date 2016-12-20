#include<iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode (int x):val(x),left(NULL),right(NULL){}
};
class Solution{
public:
	
	int maxDepth(TreeNode * root)
	{
		if (!root)return 0;
		else
		{
			int hl=maxDepth(root->left);
			int hr=maxDepth(root->right);
			if (hl>hr)
				return ++hl;
			else 
				return ++hr;

		}
		
	}
	\
		/*
	int &left_depth(TreeNode *left)
	{
		if(left!=NULL)
		{
			depth+=1;
			return left_depth(left->left);
		}
	}
	int &right_depth(TreeNode *right)
	{
		if (right!=NULL)
		{
			depth+=1;

			return right_depth(right->right);
		}
	}
	*/
	
	

};
int main(int argc,char **argv)
{
	TreeNode *root;
	TreeNode *tep=NULL;
	root->val=10;
	root->left=NULL;
	root->right=root;
	tep=root;
	root=root->right;
	root->val=20;
	root->left=NULL;
	root->right=NULL;
	Solution a;
	cout<<a.maxDepth(tep)<<endl;
	return 0;


}