// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
// Bellman ford implementation
// REF : https://www.youtube.com/watch?v=LKfIjVZ6kg4

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    
	    for(int i = 0; i < n-1; ++i)
	    {
	        for(auto edge : edges)
	        {
	            int a = edge[0];
	            int b = edge[1];
	            int w = edge[2];
	            
	            if(dist[a] != INT_MAX)
	                dist[b] = min(dist[b], dist[a] + w);
	        }
	    }
	    
	    for(auto edge : edges)
	    {
	        int a = edge[0];
	        int b = edge[1];
	        int w = edge[2];
	        
	        if(dist[a] + w < dist[b])
	            return true;
	    }
	    return false;
	}
};
