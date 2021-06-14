// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1#
// Decent

/*
Given a binary tree you need to check if it follows max heap property or not.

Input:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, 
pointer to left child and pointer to right child.There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if property holds else false.

Example 1:
Input:
      5
    /  \
   2    3
Output: 1

Example 2:
Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/

class Solution {
  public:
    int totalNodes = 0;
    
    int count(Node* root)
    {
        if(!root)
            return 0;
        
        return 1+count(root->left)+count(root->right);
    }
    
    bool rec(Node* root, int index)
    {
        if(!root)
            return true;
        
        if(index >= totalNodes)
            return false;
        
        if(root->left && root->left->data > root->data)
            return false;
        
        if(root->right && root->right->data > root->data)
            return false;
        
        return rec(root->left, 2*index+1) && rec(root->right, 2*index+2);
    }
    
    bool isHeap(struct Node * root)
    {
        totalNodes = count(root);
        return rec(root, 0);
    }
};
