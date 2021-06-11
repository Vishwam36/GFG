// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#
// Easy

/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

Example 1:
Input:
      1
    /   \
   2     3
Output: 1 2 3


Example 2:
Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input 
and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
*/

class Solution{
    public:
    vector<int> v;
    int i = 0;
    
    void get(Node* root)
    {
        if(!root)
            return;
        
        get(root->left);
        v.push_back(root->data);
        get(root->right);
    }
    
    void set(Node* root)
    {
        if(!root)
            return;
        
        set(root->left);
        root->data = v[i++];
        set(root->right);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        get(root);
        sort(v.begin(), v.end());
        set(root);
        return root;
    }
};
