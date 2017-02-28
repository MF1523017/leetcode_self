// Merge Sorted Array.cpp : 定义控制台应用程序的入口点。
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.The number of elements initialized in nums1 and nums2 are m and n respectively.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using std::vector;
class Solution {
public:
	//better
	void merge1(int A[], int m, int B[], int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			if (A[i] > B[j])
				A[k--] = A[i--];
			else
				A[k--] = B[j--];
		}
		while (j >= 0)
			A[k--] = B[j--];
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = 0;
		int j = 0;
		while (j<n)
		{
			if (nums2[j] >= nums1[i])
			{
				while (nums2[j] >= nums1[i] && i<j + m)
					i++;
				i--;
				int k = nums1.size() - 1;
				for (; k>i + 1; --k)
				{
					nums1[k] = nums1[k - 1];
				}
				nums1[k] = nums2[j];
				j++;
				i += 2;
			}
			else
			{
				int k = nums1.size() - 1;
				for (; k>i; --k)
				{
					nums1[k] = nums1[k - 1];
				}
				nums1[k] = nums2[j];
				j++;
				i++;
			}
		}
	}
};
int main()
{
	vector<int> nums1({ 1,2,3,0,0,0 });
	vector<int> nums2({ 2,5,6 });
	Solution test;
	test.merge(nums1, 3, nums2, 3);
	return 0;
}

