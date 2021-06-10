// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1#
// Easy

/*
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

Example 1:
Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}

Example 2:
Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and 
returns the maximum value.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^3
1 ≤ arr[i] ≤ 10^5
*/

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    for(int i = 0; i < n; ++i)
	        dp[i] = arr[i];
	    
	    for(int i = 1; i < n; ++i)
	        for(int j = 0; j < i; ++j)
	            if(arr[i] > arr[j])
	                dp[i] = max(dp[i], arr[i]+dp[j]);
	    
      // dp[i] shows maximum sum increasing subsequence if ssubequence ends at i (ith element is included)
	    return *max_element(dp, dp+n);
	}  
};
