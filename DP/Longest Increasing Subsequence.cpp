// By Vishwam Shriram Mundada
// It is given under DP. 
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// decent 
// https://www.youtube.com/watch?v=qW1O1a40-No

int longestSubsequence(int n, int a[])
{
    vector<int> v;
    v.push_back(a[0]);
    for(int i = 1; i < n; ++i)
    {
        if(a[i] < v.back())
        {
            int index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[index] = a[i];
        }
        if(a[i] > v.back())
        {
            v.push_back(a[i]);
        }
    }
    return v.size();
}
