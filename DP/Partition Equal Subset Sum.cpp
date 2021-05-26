// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
// Standard
// Ref : https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8

/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:
Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:
Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes 
the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.

Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)

Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
*/

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += arr[i];
        
        if(sum % 2 != 0)
            return false;
        
        sum = sum/2;
        
        bool dp[n+1][sum+1];
        
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= sum; ++j)
                if(j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = false;
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= sum; ++j)
            {
                bool include = false;
                bool not_include = dp[i-1][j];
                
                if(j - arr[i-1] >= 0)
                    include = dp[i-1][j-arr[i-1]];
                
                dp[i][j] = include || not_include;
            }
        }
        return dp[n][sum];
    }
};
