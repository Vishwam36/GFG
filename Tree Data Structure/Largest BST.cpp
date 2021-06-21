// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/largest-bst/1#
// Good question

/*
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Example 1:
Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.

Example 2
Input: 6 6 3 N 2 9 3 N 8 8 2
            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 
Output: 2
Explanation: The following sub-tree is a
BST of size 2: 
       2
    /    \ 
   N      8

Your Task:
You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input 
and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100000
1 <= Data of a node <= 1000000
*/

struct info
{
    int size; // size of tree
    int min; // minimum element of tree
    int max; // maximum element of tree
    int ans; // ans from its subtrees
    bool isBST; // its BST or not
};

info rec(Node* root)
{
    if(!root)
        return {0, INT_MAX, INT_MIN, 0, true};
    
    info l = rec(root->left);
    info r = rec(root->right);
    
    if(!l.isBST || !r.isBST || (root->data <= l.max || root->data >= r.min)) // current node cant be included in ans
        return {1+l.size+r.size, 
                min(min(r.min, l.min), root->data),
                max(max(l.max, r.max), root->data),
                max(l.ans, r.ans),
                false};
    
    return {1+l.size+r.size, 
            min(min(r.min, l.min), root->data),
            max(max(l.max, r.max), root->data),
            l.size+r.size+1,
            true};
}

int largestBst(Node *root)
{
	return rec(root).ans;
}
