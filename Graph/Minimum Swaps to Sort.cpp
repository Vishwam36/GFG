// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1#
// Good. DFS

/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Example 1:
Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.

Example 2:
Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and 
returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0. 

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
1 ≤ numsi ≤ 10^6
*/

class Solution 
{
    public:
    vector<bool> vis;
    
    int dfs(int src, int adj[], int cnt)
    {
        vis[src] = 1;
        if(!vis[adj[src]])
            return dfs(adj[src], adj, cnt+1);
        
        return cnt;
    }
    
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int, int> > v;
	    for(int i = 0; i < n; ++i)
	        v.push_back({nums[i], i});
	    
	    sort(v.begin(), v.end()); // v will store what v[i].second th  elements real position is i
	    
	    int adj[n];
	    for(int i = 0; i < n; ++i)
	        adj[i] = v[i].second;
	    
	    vis = vector<bool>(n, 0);
	    int ans = 0;
	    for(int i = 0; i < n; ++i)
	        if(!vis[i])
	            ans += dfs(i, adj, 0);
	    
	    return ans;
	}
};
