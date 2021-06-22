// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#
// Easy

/*
Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is 6, -3, -10 which gives product as 180.

Example 2:
Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is 2, 3, 4, 5 which gives product as 120.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters 
and returns an integer denoting the answer.

Note: Use 64-bit integer data type to avoid overflow.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 500
-10^2 ≤ Arri ≤ 10^2
*/

class Solution{
public:
	long long maxProduct(int *arr, int n) 
	{
	    long long a1 = 1, a2 = 1, max1 = INT_MIN, max2 = INT_MIN;
	    for(int i = 0; i < n; ++i)
	    {
	        a1 *= (long long)arr[i];
	        max1 = max(max1, a1);
	        if(a1 == 0)
	            a1 = 1;
	    }
	    for(int i = n-1; i >= 0; --i)
	    {
	        a2 *= (long long)arr[i];
	        max2 = max(max2, a2);
	        if(a2 == 0)
	            a2 = 1;
	    }
	    return max(max1, max2);
	}
};
