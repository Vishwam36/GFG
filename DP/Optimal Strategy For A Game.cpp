// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#
// Easy
// REF : https://www.youtube.com/watch?v=VwjKZQCaTC8

/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. 
You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:
Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)

Example 2:
Input:
N = 4
A[] = {8,15,3,7}
Output: 22
Explanation: The user collects maximum
value as 22(7 + 15)

Your Task:
Complete the function maximumAmount() which takes an array arr[] (represent values of N coins) and N as number of coins as a parameter and returns the
maximum possible amount of money you can win if you go first.

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N*N)

Constraints:
2 <= N <= 10^3
1 <= Ai <= 10^6
*/

int dp[1001][1001];

long long rec(int l, int r, int a[])
{
    if(l == r)
        return a[l];
    if(l > r)
        return 0;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    // after I choose my element, opponent will take maximum amount and leave minimum for me
    long long a1 = min(rec(l+1, r-1, a), rec(l+2, r, a)) + a[l];
    long long a2 = min(rec(l+1, r-1, a), rec(l, r-2, a)) + a[r];
    
    return dp[l][r] = max(a1, a2);
}

long long maximumAmount(int arr[], int n) 
{
    memset(dp, -1, sizeof(dp));
    return rec(0, n-1, arr);
}
