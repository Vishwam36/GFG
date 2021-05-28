// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
// Decent, merge sort used

/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count 
is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.

Your Task:
You don't need to read input or print anything. Your task is to complete the function inversionCount() which takes the array arr[] and the size of the array 
as inputs and returns the inversion count of the given array.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*10^5
1 ≤ arr[i] ≤ 10^18
*/

class Solution{
public:
    long long ans = 0;
    
    void merge(vector<long long> &a, vector<long long> &l, vector<long long> &r)
    {
        int nl = l.size();
        int nr = r.size();
        
        int i = 0, j = 0, k = 0;
        
        while(i < nl && j < nr)
        {
            if(l[i] <= r[j])
            {
                a[k] = l[i];
                ++i;
            }
            else
            {
                ans += nl-i; // the only extra line apart from original merge sort
                a[k] = r[j];
                ++j;
            }
            ++k;
        }
        
        while(i < nl)
        {
            a[k] = l[i];
            ++i;
            ++k;
        }
        
        while(j < nr)
        {
            a[k] = r[j];
            ++j;
            ++k;
        }
    }
    
    void merge_sort(vector<long long> &a)
    {
        int n = a.size();
        if(n <= 1)
            return;
        
        int mid = n/2;
        vector<long long> l(mid);
        vector<long long> r(n-mid);
        
        for(int i = 0; i < mid; ++i)
            l[i] = a[i];
        for(int i = mid; i < n; ++i)
            r[i-mid] = a[i];
        
        merge_sort(l);
        merge_sort(r);
        
        merge(a, l, r);
    }
    
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        vector<long long> a;
        a.assign(arr, arr+N);
        merge_sort(a);
        return ans;
    }

};
