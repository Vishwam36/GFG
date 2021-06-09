// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#
// Good question
// REF : https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38&t=5s

/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Example 1:
Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

Example 2:
Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and 
returns number of possible ways modulo 1003.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)

Constraints:
1 ≤ N ≤ 200
*/

class Solution{
public:
    int dp[201][201][2];
    
    int rec(int l, int r, bool isTrue, string s)
    {
        if(l == r)
        {
            if(isTrue)
                return s[l] == 'T';
            else
                return s[l] == 'F';
        }
        
        if(dp[l][r][isTrue] != -1)
            return dp[l][r][isTrue];
        
        int ans = 0;
        for(int k = l+1; k <= r-1; k+=2)
        {
            int lt = dp[l][k-1][true] == -1 ? rec(l, k-1, true, s) : dp[l][k-1][true];
            int lf = dp[l][k-1][false] == -1 ? rec(l, k-1, false, s) : dp[l][k-1][false];
            int rt = dp[k+1][r][true] == -1 ? rec(k+1, r, true, s) : dp[k+1][r][true];
            int rf = dp[k+1][r][false] == -1 ? rec(k+1, r, false, s) : dp[k+1][r][false];
            
            if(isTrue)
            {
                if(s[k] == '|')
                    ans += lt*rt + lf*rt + lt*rf;
                else if(s[k] == '&')
                    ans += lt*rt;
                else
                    ans += lt*rf + lf*rt;
            }
            else
            {
                if(s[k] == '|')
                    ans += lf*rf;
                else if(s[k] == '&')
                    ans += lf*rf + lt*rf + lf*rt;
                else
                    ans += lt*rt + lf*rf;
            }
            ans %= 1003;
        }
        return dp[l][r][isTrue] = ans;
    }

    int countWays(int n, string s)
    {
        memset(dp, -1, sizeof(dp));
        return rec(0, s.size()-1, true, s);
    }
};
