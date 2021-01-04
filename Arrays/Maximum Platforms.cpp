// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

// Program to find minimum number of platforms
// required on a railway station

// sorted arrival and departure events according to timings
// print sorted vector to understand clearly

#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    int ans = 0, busy = 0;
    vector <pair<int, char> > v;
    
    for(int i = 0; i < n; ++i)
    {
        v.push_back( make_pair(arr[i], 'a') );
        v.push_back( make_pair(dep[i], 'd') );
    }
    
    sort(v.begin() , v.end());
    
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i].second == 'a')
        {
            busy++;
            ans = max(ans, busy);
        }
        else
        {
            busy--;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
           for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
