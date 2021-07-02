// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
// IMP, Kosaraju algorithm
// REF : https://www.youtube.com/watch?v=Rs6DXyWpWrI&t=1124s

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*10^6
*/

class Solution
{
	public:
	int n;
	stack<int> s;
	vector<bool> vis;
	
	void dfs(int u, vector<int> adj[])
	{
	    vis[u] = 1;
	    
	    for(auto v : adj[u])
	        if(!vis[v])
	            dfs(v, adj);
	    
	    s.push(u);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        n = V;
        vis = vector<bool>(n, false);
        
        for(int i = 0; i < n; ++i)
            if(!vis[i])
                dfs(i, adj);
        
        vector<int> revAdj[n];
        for(int u = 0; u < n; ++u)
            for(auto v : adj[u])
                revAdj[v].push_back(u);
        
        int ans = 0;
        vis = vector<bool>(n, false);
        while(!s.empty())
        {
            int curr = s.top(); s.pop();
            
            if(vis[curr])
                continue;
            
            dfs(curr, revAdj);
            ++ans;
        }
        
        return ans;
    }
};
