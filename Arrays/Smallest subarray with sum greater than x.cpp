// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#
// Easy

/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:
Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}

Your Task:  
You don't need to read input or print anything. Your task is to complete the function sb() which takes the array A[], its size N and an integer X as inputs 
and returns the required ouput.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N, x ≤ 10^5
1 ≤ A[] ≤ 10^4
*/

class Solution{
    public:
    
    int sb(int a[], int n, int x)
    {
        int l = 0, r = 0, sum = 0, ans = INT_MAX;
        for(r = 0; r < n; ++r)
        {
            sum += a[r];
            while(l < r && sum-a[l] > x)
                sum -= a[l++];
            
            if(sum > x)
                ans = min(ans, r-l+1);
        }
        return ans;
    }
};
