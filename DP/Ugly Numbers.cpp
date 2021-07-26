// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1
// Good tricky

/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. 
By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:
Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.

Example 2:
Input:
N = 4
Output: 4
Explanation: 4th ugly number is 4.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getNthUglyNo() which takes an integer n as parameters and returns an integer
denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^4
*/

class Solution{
public:	
	#define ull unsigned long long
	
	ull getNthUglyNo(int n) 
	{
	    ull dp[n+1];
	    dp[1] = 1;
	    
	    ull p2 = 1, p3 = 1, p5 = 1,  f2, f3, f5;
	    
	    for(int i = 2; i <= n; ++i)
	    {
	        ull f2 = 2 * dp[p2];
	        ull f3 = 3 * dp[p3];
	        ull f5 = 5 * dp[p5];
	        
	        dp[i] = min({f2, f3, f5});
	        
	        if(dp[i] == f2)
	            p2++;
	        if(dp[i] == f3)
	            p3++;
	        if(dp[i] == f5)
	            p5++;
	    }
	    
	    return dp[n];
	}
};
