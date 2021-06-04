// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
// Easy

/*
Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. 
Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.

Example 1:
Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

Example 2: 
Input: N = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countFriendsPairings() which accepts an integer n and 
return number of ways in which friends can remain single or can be paired up.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^6
*/

class Solution
{
public:
    int countFriendsPairings(int n) 
    {
        int MOD = 1000000007;
        
        if(n <= 2)
            return n;
        
        // we just need two previous values
        long long dp_i_1 = 2; // dp[i-1]
        long long dp_i_2 = 1; // dp[i-2]
        long long dp_i; // current dp[i]
        
        for(int i = 3; i <= n; ++i)
        {
            dp_i = (dp_i_1 + (i-1)*dp_i_2) % MOD;
            // dp[i-1] shows if ith person remains alone then possible pairings
            // (i-1)*dp[i-2] shows ith can pair with i-1 different friends. And then remaining no. friends is i-2
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
    
        return dp_i;
    }
};
