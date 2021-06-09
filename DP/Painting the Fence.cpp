// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#
// Decent
// REF : https://www.youtube.com/watch?v=ju8vrEAsa3Q

/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color.
Since answer can be large return it modulo 10^9 + 7.

Example 1:
Input:
N=3,  K=2 
Output: 6
Explanation: We have following possible combinations:

Example 2:
Input:
N=2,  K=4
Output: 16

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. 
You just need to complete the function countWays() that takes n and k as parameters and returns the number of ways in which the fence can be painted.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ 100
*/

class Solution{
    public:
    long long countWays(int n, int k)
    {
        if(n <= 2)
            return pow(k, n);
        
        const long long MOD = 1000000007;
        long long same = k, diff = k*(k-1), total = k*k;
        
        for(int i = 3; i <= n; ++i)
        {
            same = diff;
            diff = (total * (k-1)) % MOD;
            total = (same + diff) % MOD;
        }
        return total;
    }
};
