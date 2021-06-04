// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1#
// Easy

/*
There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. 
In case, if the either of predecessor or successor is not found print -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.

Constraints:
1<=T<=100
1<=n<=100
1<=data of node<=100
1<=key<=100

Example:
Input:
2
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
65
6
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R
100

Output:
60 70
80 -1
*/

// In inorder traversal of BST values come in SORTED order

void findPreSuc(Node* root, Node*& pre, Node*& suc, int k)
{
    if(!root)
        return;
    
    if(root->key == k)
    {
        findPreSuc(root->left, pre, suc, k);
        findPreSuc(root->right, pre, suc, k);
    }
    else if(root->key < k)
    {
        if((pre && pre->key < root->key) || pre == NULL)
        {
            pre = root;
            findPreSuc(root->right, pre, suc, k);
        }
    }
    else
    {
        if((suc && suc->key > root->key) || suc == NULL)
        {
            suc = root;
            findPreSuc(root->left, pre, suc, k);
        }
    }
}
