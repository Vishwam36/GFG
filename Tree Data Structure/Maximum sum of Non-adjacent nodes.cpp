// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1#
// Easy

/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under 
a constraintthat no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children 
in consideration and vice versa.

Example 1:
Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.

Example 2:
Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.

Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter 
and returns the maximum sum as described.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 1000
*/

int rec(Node* root)
{
    if(!root)
        return 0;
    
    int taken = root->data;
    if(root->left) // if we have taken current node then we have to get sum from its grandchildren 
        taken += rec(root->left->left) + rec(root->left->right);
    if(root->right)
        taken += rec(root->right->left) + rec(root->right->right);
    
    int not_taken = rec(root->left) + rec(root->right);
    
    return max(taken, not_taken);
}

int getMaxSum(Node *root) 
{
    return rec(root);
}
