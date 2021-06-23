// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#
// Decent

/*
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Example 1 :
Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5

Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.

Example 2 :
Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only arguement
and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

Constraints:
1<=length of string<=100
*/

// REF : https://www.youtube.com/watch?v=_j7yb_nWFO8

// App 1 : O(N)

unordered_map<string, int> m;

// returns preorder of root wirh some '$'s
string rec(Node* root)
{
    if(!root)
        return "$"; // to distinguish between different structured subtrees but same preorder
    
    if(!root->left && !root->right) // not adding leaf node to map
        return to_string(root->data);
    
    string s = to_string(root->data);
    s += rec(root->left);
    s += rec(root->right);
    
    m[s]++;
    
    return s;
}

bool dupSub(Node *root)
{
    m.clear();
    rec(root);
    for(auto it = m.begin(); it != m.end(); ++it)
        if(it->second >= 2)
            return true;
    
    return false;
}


// App 2 : Brute Force
// Check for each node

Node* global;

bool check(Node* root, Node* cand)
{
    if(!root && !cand)
        return true;
    if((!root && cand) || (root && !cand))
        return false;
    
    bool ans = false;
    if(root->data == cand->data && root != cand)
        ans = ans || (check(root->left, cand->left) && check(root->right, cand->right));

    ans = ans || check(root->left, global) || check(root->right, global);
    
    return ans;
}

bool dupSub(Node *root)
{
    if(!root || (!root->left && !root->right))
        return false;
    
    bool ans = false;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr = q.front(); q.pop();
        
        if(!curr->left && !curr->right)
            continue;
        
        global = curr;
        ans = ans || check(root, curr);
        
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        
        if(ans)
            return ans;
    }
    return ans;
}
