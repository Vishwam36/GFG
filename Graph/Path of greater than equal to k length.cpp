// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/path-of-greater-than-equal-to-k-length1034/1#
// Easy, DFS

/*
Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length greater than or equal to k,(without any cycle) starting 
from a given source and ending at any other vertex.
Source vertex should always be  0.

Example 1:
Input:
V = 4 , E = 3 and K = 8
A[] = [0, 1, 5, 1, 2, 1, 2, 3, 1]
Output: 0
Explanation:
There exists no path which has a distance 
of 8. 

Example 2:
Input:
V = 9, E = 14 and K = 60
A[] = [0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9, 3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 8, 6, 7, 8, 7]
Output: 0

Your Task:  
You don't need to read input or print anything. Your task is to complete the function pathMoreThanK() which takes the integer V, Edges E, an integer K and
Array A which is having (Source, Destination, Weight) as input parameters and returns 1 if the path of at least k distance exists, else returns 0.

Expected Time Complexity: O(N!)
Expected Auxiliary Space: O(N)

Constraints:
2 ≤ V ≤ 5
1 ≤ E ≤ 20
1 ≤ K ≤ 100
*/

class Solution {
public:
    vector<bool> vis;
    
    int dfs(int u, vector<pair<int, int> > adj[])
    {
        vis[u] = 1;
        int ans = 0;
        for(auto p : adj[u])
        {
            int v = p.first;
            int w = p.second;
            
            if(!vis[v])
            {
                int temp = dfs(v, adj);
                ans = max(ans, temp+w);
            }
        }
        vis[u] = 0; // backtracking to check other paths
        return ans;
    }

    bool pathMoreThanK(int n, int e, int k, int *a) 
    {
        vis = vector<bool>(n, false);
        vector<pair<int, int> > adj[n];
        for(int i = 0; i < 3*e;)
        {
            int u = a[i++];
            int v = a[i++];
            int w = a[i++];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        return dfs(0, adj) >= k;
    } 
};
