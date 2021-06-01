// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
// Decent, Prefix Sum

/*
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

Example 1:
Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:
Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and 
returns the total number of sub-arrays with 0 sum. 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:    
1<= n <= 107
-1010 <= arri <= 10^10
*/

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) 
    {
        int ans = 0, preSum = 0;
        
        unordered_map<ll, ll> m;
        m[0]++; 
        // we are adding 0 initially because initially sum = 0
        // if we dont add this we will miss those subarrays which are starting fron index = 0
        
        for(auto num : arr)
        {
            preSum += num;
            m[preSum]++;
        }
        
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            int x = it->second;
            ans += ((x)*(x-1))/2;
        }
        
        return ans;
    }
};
