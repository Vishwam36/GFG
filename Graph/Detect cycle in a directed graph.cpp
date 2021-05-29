// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#
// IMP

// DFS Approach

class Solution
{
    public:
    vector<int> vis;
    vector<int> track;
    
    bool dfs(int src, vector<int> adj[])
    {
        vis[src] = 1; // we are sending only those in function who are unvisited
        track[src] = 1; // we are not sending tracked nodes in function
        
        for(int i = 0; i < adj[src].size(); ++i)
        {
            int child = adj[src][i];
            
            if(track[child])
                return true;
            
            if(!vis[child])
                if(dfs(child, adj))
                    return true;
        }
        track[src] = 0; // untrack
        return false;
    }
	
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vis.resize(V);
	   	track.resize(V);
	   	
	   	for(int i = 0; i < V; ++i)
	   	    if(!vis[i] && dfs(i, adj))
	   	        return true;
	   	
	    return false;
	}
};

// BFS Approach

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> indegree(V, 0);
	   	vector<bool> vis(V, false);
	   	
	   	for(int i = 0; i < V; ++i)
	   	    for(int j = 0; j < adj[i].size(); ++j)
	   	        indegree[adj[i][j]]++;
	   	
	   	queue<int> q;
	   	for(int i = 0; i < V; ++i)
	   	    if(indegree[i] == 0)
	   	    {
	   	        q.push(i);
	   	        vis[i] = 1;
	   	    }
	   	
	   	while(!q.empty())
	   	{
	   	    int curr = q.front();
	   	    q.pop();
	   	    
	   	    for(int i = 0; i < adj[curr].size(); ++i)
	   	    {
	   	        int child = adj[curr][i];
	   	        indegree[child]--;
	   	        if(indegree[child] == 0)
	   	        {
	   	            q.push(child);
	   	            vis[child] = 1;
	   	        }
	   	    }
	   	}
	   	
	   	int countVis = 0;
	   	for(int i = 0; i < V; ++i)
	   	    if(vis[i])
	   	        countVis++;
	   	
	   	if(countVis < V) // we cant visit all nodes. so there is a cycle
	   	    return true;
	   	
	   	return false;
	}
};
