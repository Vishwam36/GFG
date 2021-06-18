// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#
// Easy

/*
Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number 
of times to make B.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Example 1:
Input:
N = 4
arr[] = {7,2,6,5}
B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)

Example 2:
Input:
N = 11
arr[] = {6,5,7,1,8,2,9,9,7,7,9}
B = 6
Output:
(1 1 1 1 1 1)
(1 1 1 1 2)
(1 1 2 2)
(1 5)
(2 2 2)
(6)

Expected Time Complexity: O(X2 * 2N), where X is average of summation B/arri for every number in the array.
Expected Auxiliary Space: O(X * 2N)

Constraints:
1 <= N <= 30
1 <= A[i] <= 20
1 <= B <= 100
*/

class Solution 
{
    public:
    vector<vector<int> > ans;
    
    void rec(int idx, vector<int> &a, vector<int> &temp, int b)
    {
        if(b == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < a.size(); ++i)
        {
            if(b - a[i] >= 0)
            {
                temp.push_back(a[i]);
                rec(i, a, temp, b-a[i]);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &a, int b)
    {
        vector<int> temp;
        sort(a.begin(), a.end());
        
        a.erase(unique(a.begin(), a.end()), a.end());
        
        rec(0, a, temp, b);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
