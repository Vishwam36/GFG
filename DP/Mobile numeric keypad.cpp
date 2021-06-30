// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1#
// Easy
// REF : https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/

/*
Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button.You are not allowed to press bottom row corner buttons
(i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

Example 1:
Input: 1
Output: 10
Explanation: Number of possible numbers 
would be 10 (0, 1, 2, 3, …., 9)

Example 2:
Input: N = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11,
12, 14, 22, 21, 23, 25 and so on.
If we start with 0, valid numbers 
will be 00, 08 (count: 2)
If we start with 1, valid numbers 
will be 11, 12, 14 (count: 3)
If we start with 2, valid numbers 
will be 22, 21, 23,25 (count: 4)
If we start with 3, valid numbers 
will be 33, 32, 36 (count: 3)
If we start with 4, valid numbers 
will be 44,41,45,47 (count: 4)
If we start with 5, valid numbers 
will be 55,54,52,56,58 (count: 5) 
and so on..

Your Task:  
You don't need to read input or print anything. Complete the function getCount() which takes N as input parameter and returns the integer value

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 25
*/

// App 1 :
// TC : O(N)
// SC : O(N)

class Solution{
	public:
	vector<vector<int> > adj = {{0, 8},
	                            {1, 2, 4},
	                            {2, 1, 3, 5},
	                            {3, 2, 6},
	                            {4, 1, 5, 7},
	                            {5, 2, 4, 6, 8},
	                            {6, 3, 5, 9},
	                            {7, 4, 8},
	                            {8, 5, 7, 9, 0},
	                            {9, 6, 8}};
	
	vector<vector<long long> > dp;
	
	long long rec(int num, int rem)
	{
	    if(rem == 0)
	        return 1;
	    
	    if(dp[num][rem] != -1)
	        return dp[num][rem];
	    
	    long long ans = 0;
	    for(auto next : adj[num])
	        ans += rec(next, rem-1);
	    
	    return dp[num][rem] = ans;
	}
	
	long long getCount(int n)
	{
	    dp = vector<vector<long long> >(10, vector<long long>(n, -1));
	    
	    long long ans = 0;
		for(int i = 0; i <= 9; ++i)
		    ans += rec(i, n-1);
		
		return ans;
	}
};


// App 2 : 
// TC : O(N * 10);
// SC : O(1)

class Solution{
	public:
	vector<vector<int> > adj = {{0, 8},
	                            {1, 2, 4},
	                            {2, 1, 3, 5},
	                            {3, 2, 6},
	                            {4, 1, 5, 7},
	                            {5, 2, 4, 6, 8},
	                            {6, 3, 5, 9},
	                            {7, 4, 8},
	                            {8, 5, 7, 9, 0},
	                            {9, 6, 8}};
	
	// get previous values of v1 into v2
	void get(vector<long long> &v2, vector<long long> &v1)
	{
	    for(int i = 0; i < 10; ++i)
	    {
	        v2[i] = 0;
	        for(auto next : adj[i])
	            v2[i] += v1[next];
	    }
	}
	
	long long getCount(int n)
	{
	    int turn = 0;
	    vector<long long> v1(10, 1);
	    vector<long long> v2(10, 0);
	    
	    for(int i = 0; i < n-1; ++i)
	    {
	        if(turn == 0)
	        {
	            get(v2, v1);
	            turn = 1;
	        }
	        else
	        {
	            get(v1, v2);
	            turn = 0;
	        }
	    }
	    
	    long long ans = 0;
	    if(turn == 0)
	        for(int i = 0; i < 10; ++i)
	            ans += v1[i];
	    else
	        for(int i = 0; i < 10; ++i)
	            ans += v2[i];
	    
	    return ans;
	}
};
