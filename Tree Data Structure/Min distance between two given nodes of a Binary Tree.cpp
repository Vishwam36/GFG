// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#
// Decent

/*
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:
Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values 
a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10^4
1 <= Data of a node <= 10^5
*/

int distance(Node* root, int child) // distnce of root->child given that root is ancestor of child or root = child
{
    if(!root)
        return 0;
    
    if(root->data == child)
        return 1;
    
    int l = distance(root->left, child);
    int r = distance(root->right, child);
    
    if(l)
        return l+1;
    if(r)
        return r+1;
    
    return 0;
}

Node* lca(Node* root, int a, int b)
{
    if(!root)
        return NULL;
    
    if(root->data == a || root->data == b)
        return root;
        
    Node* l = lca(root->left, a, b);
    Node* r = lca(root->right, a, b);
    
    if(l && r)
        return root;
    
    return l ? l : r;
}

int findDist(Node* root, int a, int b) 
{
    Node* parent = lca(root, a, b); // find least common ancestor
    return distance(parent, a) + distance(parent, b)-2;
}
