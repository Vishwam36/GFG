// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#
// Easy

/*
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

Example 1:
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

Example 2:
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Ai <= 1010
*/

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int n, int s)
    {
        long long sum = 0;
        int l = 0, r = 0;

        while(sum < s && r < n)
            sum += arr[r++];
        
        if(sum == s)
            return vector<int>({1, r});
        
        while(r < n)
        {
            sum -= arr[l++];
            
            while(sum < s && r < n)
                sum += arr[r++];
            
            if(sum == s)
                return vector<int>({l+1, r});
        }
        
        while(sum > s)
            sum -= arr[l++];
        
        if(sum == s)
            return vector<int>({l+1, r});
        
        return vector<int>({-1});
    }
};
