// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#
// Easy

/*
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, 
A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

Example 1:
Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree
is mirror image of the first.

Example 2:
Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree
isn't mirror image of the first.

Your Task:
You don't need to read input or print anything. Your task is to complete the function checkMirrorTree() which takes 2 Integers n, and e;  and two arrays A[] 
and B[] of size 2*e as input and returns 1 if the trees are mirror images of each other and 0 if not.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n,e <= 10^5
*/

class Solution {
  public:
    int checkMirrorTree(int n, int e, int a[], int b[]) 
    {
        unordered_map<int, vector<int> > m1, m2;
        for(int i = 0; i < 2*e; i+=2)
        {
            m1[a[i]].push_back(a[i+1]);
            m2[b[i]].push_back(b[i+1]);
        }
        
        for(auto it = m1.begin(); it != m1.end(); ++it)
        {
            int root = it->first;
            if(it->second[0] == m2[root].back() && it->second.back() == m2[root][0])
                continue;
            else
                return false;
        }
        return true;
    }
};
