// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/two-water-jug-problem3402/1#
// Decent, BFS

/*
You are at the side of a river. You are given a m litre jug and a n litre jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to 
allow measuring smaller quantities. You have to use the jugs to measure d litres of water where d < n. Determine the minimum no of operations to be performed to 
obtain d litres of water in one of jug.
The operations you can perform are:

Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.

Example 1:
Input: m = 3, n = 5, d = 4
Output: 6
Explanation: Operations are as follow-
1. Fill up the 5 litre jug.
2. Then fill up the 3 litre jug using 5 litre
   jug. Now 5 litre jug contains 2 litre water.
3. Empty the 3 litre jug.
4. Now pour the 2 litre of water from 5 litre 
   jug to 3 litre jug.
5. Now 3 litre jug contains 2 litre of water 
   and 5 litre jug is empty. Now fill up the 
   5 litre jug.
6. Now fill one litre of water from 5 litre jug 
   to 3 litre jug. Now we have 4 litre water in 
   5 litre jug.
   
Example 2:
Input: m = 8, n = 56, d = 46
Output: -1
Explanation: Not possible to fill any one of 
the jug with 46 litre of water.

Your Task:
You don't need to read or print anything. Your task is to complete the function minSteps() which takes m, n and d ans input parameter and 
returns the minimum number of operation to fill d litre of water in any of the two jug. 

Expected Time Comeplxity: O(d)
Expected Space Complexity: O(1)

Constraints:
1 ≤ n ≤ m ≤ 100
1 ≤ d ≤ 100
*/

class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	   bool vis[101][101];
	   memset(vis, 0, sizeof(vis));
	   
	   queue<pair<int, int> > q;
	   q.push({0, 0});
	   int level = 0;
	   vis[0][0] = 1;
	   
	   while(!q.empty())
	   {
	       int len = q.size();
	       while(len--)
	       {
	           auto p = q.front(); q.pop();
	           int x = p.first;
	           int y = p.second;
	       
	           if(x < 0 || y < 0 || x > m || y > n)
	               continue;
	       
	           if(x == d || y == d)
	               return level;
	           
	           // empty jug1
	           if(vis[0][y] == 0)
	           {
	               q.push({0, y});
	               vis[0][y] = 1;
	           }
	           // empty jug2
	           if(vis[x][0] == 0)
	           {
	               q.push({x, 0});
	               vis[x][0] = 1;
	           }
	           // fill jug1
	           if(vis[m][y] == 0)
	           {
	               q.push({m, y});
	               vis[m][y] = 1;
	           }
	           // fill jug2
	           if(vis[x][n] == 0)
	           {
	               q.push({x, n});
	               vis[x][n] = 1;
	           }
	           // empty jug1 in jug2
	           if(n-y > x && vis[0][x+y] == 0)
	           {
	               q.push({0, y+x});
	               vis[0][x+y] = 1;
	           }
	           // fill jug2 full using jug1
	           else if(x >= n-y && vis[x-(n-y)][n] == 0)
	           {
	               q.push({x-(n-y), n});
	               vis[x-(n-y)][n] = 1;
	           }
	           // empty jug2 in jug1
	           if(m-x > y && vis[x+y][0] == 0)
	           {
	               q.push({x+y, 0});
	               vis[x+y][0] = 1;
	           }
	           // fill jug1 full using jug2
	           else if(y >= m-x && vis[m][y-(m-x)] == 0)
	           {
	               q.push({m, y-(m-x)});
	               vis[m][y-(m-x)] = 1;
	           }
	        }
	        level++;
	   }
	   return -1; // not possible
	}
};
