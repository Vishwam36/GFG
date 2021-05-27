// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/topological-sort/1#
// Standard

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    vector<int> indegree(V, 0);
	    
	    for(int i = 0; i < V; ++i)
	        for(int j = 0; j < adj[i].size(); ++j)
	            indegree[adj[i][j]]++;
	    
	    queue<int> q;
	    for(int i = 0; i < V; ++i)
	        if(indegree[i] == 0)
	            q.push(i);
	    
	    while(!q.empty())
	    {
	        int curr = q.front();
	        ans.push_back(curr);
	        q.pop();
	        
	        for(int i = 0; i < adj[curr].size(); ++i)
	        {
	            int child = adj[curr][i];
	            indegree[child]--;
	            
	            if(indegree[child] == 0)
	                q.push(child);
	        }
	    }
	    return ans;
	}
};
