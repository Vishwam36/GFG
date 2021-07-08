// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/count-element-occurences/1#
// 

/*
Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

Example 1:
Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.

Example 2:
Input:
N = 4
arr[] = {2,3,3,2}
k = 3
Output: 2
Explanation: In the given array, 3 and 2 
are the only elements that appears more 
than n/k times. So the count of elements 
are 2.

Your Task:
The task is to complete the function countOccurence() which returns count of elements with more than n/k times appearance.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^4
1 <= a[i] <= 10^6
1 <= k <= N
*/

// App 1 : 
// Easy Hashing
// TC : O(N)
// SC : O(N)

class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) 
    {
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; ++i)
            m[arr[i]]++;
        
        int ans = 0;
        for(auto it = m.begin(); it != m.end(); ++it)
            if(it->second > n/k)
                ans++;
        
        return ans;
    }
};

// App 2 : 
// TC : O(N*K)
// SC : O(K)

// REF : https://www.youtube.com/watch?v=cIgDFIoA_s0

struct Element
{
    int num;
    int count;
};

class Solution
{
    public:
    
    int numCount(int a[], int n, int cand)
    {
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(a[i] == cand)
                ++cnt;
        
        return cnt;
    }
    
    int countOccurence(int arr[], int n, int k) 
    {
        if(k <= 1)
            return 0;
        
        Element container[k-1];
        
        for(int i = 0; i < k-1; ++i)
            container[i].count = 0;
        
        for(int i = 0; i < n; ++i)
        {
            int j = 0;
            for(j = 0; j < k-1; ++j)
                if(arr[i] == container[j].num)
                {
                    container[j].count++; // increase count if already present
                    break;
                }
            
            if(j == k-1) // arr[i] is not present in container
            {
                for(j = 0; j < k-1; ++j)
                    if(container[j].count == 0) // check if we have empty slot
                    {
                        container[j].num = arr[i];
                        container[j].count = 1;
                        break;
                    }
            }
            
            if(j == k-1) // we dont have empty slot
            {
                for(j = 0; j < k-1; ++j)
                    container[j].count--; // reduce count of all present elements
            }
        }
        
        int ans = 0;
        for(int i = 0; i < k-1; ++i)
            if(numCount(arr, n, container[i].num) > n/k)
                ++ans;
        
        return ans;
    }
};
