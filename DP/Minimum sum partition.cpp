// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
// Decent, based on subset sum
// Minimum Subset Sum Difference
// Ref : https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10&t=286s

/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that 
the absolute difference between their sums is minimum and find the minimum difference

Example 1:
Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value

Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)

Constraints:
1 ≤ N*|sum of array elements| ≤ 10^6
*/

class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{
	    int sum = 0;
	    for(int i = 0; i < n; ++i)
	        sum += arr[i];
	    
	    int total = sum;
	    // for absolute diff to be minimum sum of one subset should be as close as total_sum/2
	    sum = sum/2; // sum = total_sum/2
	    
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
	            int include = false;
	            int not_include = dp[i-1][j];
	            
	            if(j - arr[i-1] >= 0)
	                include = dp[i-1][j-arr[i-1]];
	            
	            dp[i][j] = include || not_include;
	        }
	    }
	    
	    // checking possible closest sum to total_sum/2 
	    for(int i = sum; i >= 0; --i)
	        if(dp[n][i])
	            return abs(i - (total-i)); // difference
	} 
};
