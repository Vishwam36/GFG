// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#
// Decent

/*
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:
Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.

Example 2:
Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.

User Task:
Complete the function findNum() which takes an integer N as input parameters, and returns the answer.

Expected Time Complexity: O(log2 N * log5 N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 10^4
*/

class Solution
{
    public:
    bool can(int cand, int n)
    {
        int i = 5, z = 0;
        while(cand/i > 0)
        {
            z += cand/i;
            i *= 5;
        }
        if(z >= n)
            return true;
        return false;
    }
    
    int findNum(int n)
    {
        int l = 0, r = n*5, mid;
        while(r-l > 1)
        {
            mid = (l+r)/2;
            
            if(can(mid, n))
                r = mid;
            else
                l = mid;
        }
        if(can(l, n))
            return l;
        return r;
    }
};
