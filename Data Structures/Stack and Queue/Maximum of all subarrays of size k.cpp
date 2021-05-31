// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
// Good, Sliding window is good approach

/*
Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:
Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6

Example 2:
Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10
3rd contiguous subarray = {10 7 9 4}, Max = 10
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, 
Max = 15
6th contiguous subarray = {4 15 12 90},
Max = 90
7th contiguous subarray = {15 12 90 13}, 
Max = 90

Your Task:  
You dont need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N and K as input parameters and 
returns a list of integers denoting the maximum of every contiguous subarray of size K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ arr[i] <= 10^7
*/

// App 1 : Using Sliding window and deque
// Good Approach
// REF : https://www.youtube.com/watch?v=xFJXtB5vSmM

class Solution
{
    public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> q;
        
        int i = 0, j = 0;
        for(; j < k; ++j)
        {
            while(!q.empty() && arr[q.back()] <= arr[j])
                q.pop_back();
            
            q.push_back(j);
        }
        ans.push_back(arr[q.front()]);
        
        for(; j < n; ++j, ++i)
        {
            while(!q.empty() && arr[q.back()] <= arr[j])
                q.pop_back();
            
            q.push_back(j);
            
            if(q.front() == i)
                q.pop_front();
            
            ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};


// App 2 : Using Stack
// REF : https://www.youtube.com/watch?v=tCVOQX3lWeI

class Solution
{
    public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> next_greater(n); // storing index of next greater element
        next_greater[n-1] = n-1;
        
        stack<int> s;
        s.push(n-1);
        
        for(int i = n-2; i >= 0; --i)
        {
            while(!s.empty() && arr[s.top()] <= arr[i])
                s.pop();
            
            if(!s.empty())
                next_greater[i] = s.top();
            else
                next_greater[i] = i;
            
            s.push(i);
        }
        
        vector<int> ans;
        
        int i = 0, j = 0;
        
        for(int i = 0; i <= n-k; ++i)
        {
            if(j < i)
                j = i;
            
            while(j < i+k)
            {
                if(next_greater[j] > j && next_greater[j] < i+k)
                    j = next_greater[j];
                else
                    break;
            }
            ans.push_back(arr[j]);
        }
        
        return ans;
    }
};
