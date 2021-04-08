// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
// Bellman ford implementation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    int m = edges.size();
	    int dist[n];
	    for(int i = 0; i < n; ++i)
	        dist[i] = INT_MAX;
	    
	    dist[0] = 0;
	    
	    for(int i = 0; i < n-1; ++i)
	    {
	        for(int j = 0; j < m; ++j)
	        {
	            int a = edges[j][0];
	            int b = edges[j][1];
	            int w = edges[j][2];
	            
	            if(dist[a] != INT_MAX && dist[a] + w < dist[b])
	            {
	                dist[b] = dist[a] + w;
	            }
	        }
	    }
	    
	    for(int i = 0; i < m; ++i)
	    {
	        int a = edges[i][0];
	        int b = edges[i][1];
	        int w = edges[i][2];
	        
	        if(dist[a] != INT_MAX && dist[a] + w < dist[b])
	        {
	            return 1;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
