// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

#include<bits/stdc++.h>
using namespace std;

vector <long long> nextLargerElement(long long arr[], int n)
{
    vector <pair<long long, long long> > v;
    vector <long long> ans;

    stack<pair<long long, long long> > s;
    s.push(make_pair(arr[0],0));
    for(int i=1;i<n;++i)
    {
        if(s.empty())
        {
            s.push(make_pair(arr[i],i));
            continue;
        }
        while(!s.empty() && s.top().first < arr[i])
        {
            v.push_back(make_pair(s.top().second, arr[i]));
            s.pop();
        }
        
        s.push(make_pair(arr[i],i));
    }
    while(!s.empty())
    {
        v.push_back(make_pair(s.top().second, -1));
        s.pop();
    }
    sort(v.begin(), v.end());
    for(int i=0;i<n;++i)
    {
        ans.push_back(v[i].second);
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
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
