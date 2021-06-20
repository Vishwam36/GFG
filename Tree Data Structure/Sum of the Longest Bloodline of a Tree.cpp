// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#
// Easy

/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root 
to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:
Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13

Example 2:
Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11

Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree 
as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 10^4
1 <= Data of a node <= 10^4
*/

class Solution
{
public:
    int ans = 0;
    int max_h = 0;
    
    void rec(Node* root, int h, int sum)
    {
        if(!root)
        {
            if(max_h < h)
            {
                max_h = h;
                ans = sum;
            }
            else if(max_h == h)
            {
                ans = sum;
            }
            return;
        }
        
        rec(root->left, h+1, sum+root->data);
        rec(root->right, h+1, sum+root->data);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        rec(root, 0, 0);
        return ans;
    }
};
