// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/interleaved-strings/1#
// Easy

/*
Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of A and B else returns false.
C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

Example 1:
Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X

Example 2:
Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.

Your Task:
Complete the function isInterleave() which takes three strings A, B and C as input and returns true if C is an interleaving of A and B else returns false. 
(1 is printed by the driver code if the returned value is true, otherwise 0.)

Expected Time Complexity: O(N * M)
Expected Auxiliary Space: O(N * M)
here, N = length of A, and M = length of B

Constraints:
1 ≤ length of A, B, C ≤ 100
*/

class Solution{
  public:
    int dp[101][101];
    
    bool rec(int idx, int i, int j, string &A, string &B, string &C)
    {
        if(idx == C.size())
            return true;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(C[idx] == A[i] && C[idx] == B[j])
            return dp[i][j] =  rec(idx+1, i+1, j, A, B, C) || rec(idx+1, i, j+1, A, B, C);
        
        if(C[idx] == A[i])
            return dp[i][j] = rec(idx+1, i+1, j, A, B, C);
        
        if(C[idx] == B[j])
            return dp[i][j] = rec(idx+1, i, j+1, A, B, C);
        
        return false;
    }
    
    
    bool isInterleave(string A, string B, string C) 
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, A, B, C);
    }
};
