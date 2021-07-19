// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1#
// Decent. Heap implementation

/*
Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
The task is very simple to merge the two arrays firstly keep all the elements of first array than elements second array, than apply the merge operation of heaps

Example 1:
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :

Your Task:  
You don't need to read input or print anything. Your task is to complete the function leftIndex() which takes the array a[], b[], 
its size n and m and an answer array merged[] as inputs and stores the merged max heap.

Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n, m <= 10^5
1 <= a[i], b[i] <= 2*10^5
*/

// App 1 : Easy

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        vector<int> ans;
        
        for(auto num : a)
            ans.push_back(num);
        
        for(auto num : b)
            ans.push_back(num);
            
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};

// App 2 :
// ShiftUp is not getting accepted, I dont know why. It also gives different but correct max-heap

int p(int i)
{
    return (i-1)/2;
}

int lc(int i)
{
    return i*2+1;
}

int rc(int i)
{
    return i*2+2;
}

void shiftDown(int idx, int merged[], int size)
{
    if(idx >= size-1)
        return;
    
    int swapId = idx;
    if(lc(idx) < size && merged[lc(idx)] > merged[idx])
        swapId = lc(idx);
    
    if(rc(idx) < size && merged[rc(idx)] > merged[swapId])
        swapId = rc(idx);
    
    if(swapId != idx)
    {
        swap(merged[swapId], merged[idx]);
        shiftDown(swapId, merged, size);
    }
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) 
{
    int i = 0;
    for(i = 0; i < n; ++i)
        merged[i] = a[i];
    
    for(; i < m+n; ++i)
        merged[i] = b[i-n];
    
    for(int i = (n+m)/2 -1; i >= 0; --i)
        shiftDown(i, merged, n+m);
}
