// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
// Decent
// Using unordered map is also ok

/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.


Example 2:
Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function getPairsCount() which takes arr[], n and k as input parameters and 
returns the number of pairs that have sum K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
1 <= K <= 10^8
1 <= Arr[i] <= 10^6
*/

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        int MAX = *max_element(arr, arr+n);
        int hash[MAX+1];
        memset(hash, 0, sizeof(hash));
        
        for(int i = 0; i < n; ++i)
            hash[arr[i]]++;
        
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            // if (arr[i], arr[i]) pair satisfies the condition,then ensure that 
            // count is decreased by one such that the (arr[i], arr[i]) pair is not considered
            if(arr[i] == k-arr[i])
                cnt += hash[arr[i]]-1;
            
            else if(k-arr[i] >= 0 && k - arr[i] <= MAX)
                cnt += hash[k-arr[i]];
        }
        
        return cnt/2;
    }
};
