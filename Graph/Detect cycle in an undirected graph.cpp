// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
// IMP

// BFS Approach 

class Solution 
{
    public:
    vector<bool> vis;
    
    bool bfs(int src, vector<int>adj[])
    {
        queue<pair<int, int> > q;
        q.push( {src, -1} );
        vis[src] = 1;
        
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            int curr = p.first;
            int parent = p.second;
            q.pop();
            
            for(int i = 0; i < adj[curr].size(); ++i)
            {
                int child = adj[curr][i];
                
                if(vis[child] && child != parent)
                    return true;
                
                if(!vis[child])
                {
                    q.push( {child, curr} );
                    vis[child] = 1;
                }
            }
        }
        return false;
    }
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vis.resize(V, 0);
	    
	    for(int i = 0; i < V; ++i)
	        if(!vis[i])
	            if(bfs(i, adj))
	                return true;
	    
	    return false;
	}
};

// DFS Approach

class Solution 
{
    public:
    vector<bool> vis;
    
    bool dfs(int src, int parent, vector<int>adj[])
    {
        vis[src] = 1;
        
        for(int i = 0; i < adj[src].size(); ++i)
        {
            int child = adj[src][i];
            
            if(vis[child] && child != parent)
                return true;
            
            if(!vis[child])
                if(dfs(child, src, adj))
                    return true;
        }
        return false;
    }
    
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vis.resize(V, 0);
	    
	    for(int i = 0; i < V; ++i)
	        if(!vis[i])
	            if(dfs(i, -1, adj))
	                return true;
	    
	    return false;
	}
};
