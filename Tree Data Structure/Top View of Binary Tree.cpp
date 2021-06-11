// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1#
// Decent

/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when 
the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:
Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

Your Task:
Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and 
returns a list of nodes visible from the top view from left to right. Print endline after end of printing the top view.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ Node Data ≤ 105

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function 
problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<pair<int, int> > m;
        int left = 1, right = -1;
        
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            Node* curr = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(level < left || level > right)
            {
                left = min(left, level);
                right = max(right, level);
                m.push_back({level, curr->data});
            }
            
            if(curr->left)
                q.push({curr->left, level-1});
            if(curr->right)
                q.push({curr->right, level+1});
        }
        
        sort(m.begin(), m.end());
        vector<int> res(m.size());
        for(int i = 0; i < m.size(); ++i)
            res[i] = m[i].second;
        return res;
    }
};
