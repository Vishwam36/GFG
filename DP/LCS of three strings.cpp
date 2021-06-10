// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1#
// Easy, when you know LCS

/*
Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.

Example 1:
Input:
A = "geeks", B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common
subsequence with length 5.

Example 2:
Input: 
A = "abcd", B = "efgh", C = "ijkl"
Output: 0
Explanation: There's no common subsequence
in all the strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the strings A, B, C and their lengths n1, n2, n3 
as input and returns the length of the longest common subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1<=n1, n2, n3<=100
*/

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1+1][n2+1][n3+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i <= n1; ++i)
        for(int j = 1; j <= n2; ++j)
            for(int k = 1; k <= n3; ++k)
            {
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                
                else
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
            }
    
    return dp[n1][n2][n3];
}
