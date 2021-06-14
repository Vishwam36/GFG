// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
// Easy

/*
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:
Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N 
and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. 
If a window does not contain a negative integer , then return 0 for that window.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(K)

Constraints:
1 <= N <= 10^5
1 <= A[i] <= 10^5
1 <= K <= N
*/

vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k)
{
    vector<long long> ans;
    queue<long long> q;
    for(int i = 0; i < k; ++i)
        if(a[i] < 0)
            q.push(i);
    
    if(!q.empty())
        ans.push_back(a[q.front()]);
    else
        ans.push_back(0);
    
    for(int l = 0, r = k; r < n; ++r, ++l)
    {
        if(a[r] < 0)
            q.push(r);
        if(a[l] < 0)
            q.pop();
        
        if(!q.empty())
            ans.push_back(a[q.front()]);
        else
            ans.push_back(0);
    }
    return ans;
}
