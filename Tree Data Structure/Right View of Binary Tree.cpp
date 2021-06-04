// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Easy

/*
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
    \
     8

Example 1:
Input:
       1
    /    \
   3      2
Output: 1 2

Example 2:
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60

Your Task:
Just complete the function rightView() that takes node as parameter and returns the right view as a list. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5
*/

class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        
        if(!root)
            return ans;
        
        queue<Node*> q;
        q.push(root);
        int reqLevel = 0, level = 0;
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; ++i)
            {
                Node* curr = q.front();
                q.pop();
                
                if(level == reqLevel)
                {
                    reqLevel++;
                    ans.push_back(curr->data);
                }
            
                if(curr->right)
                    q.push(curr->right);
            
                if(curr->left)
                    q.push(curr->left);
            }
            
            level++;
        }
        return ans;
    }
};
