// By Vishwam Mundada
// Back-tracking
// https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v)
{
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void makeSubsets(int a[], int n, int index, vector<int> v)
{
    if(index == n)
    {
        printVector(v);
        return;
    }
    makeSubsets(a,n,index+1,v);
    v.push_back(a[index]);
    makeSubsets(a,n,index+1,v);
}

int main()
{
    int n=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int> v;
    makeSubsets(a,n,0,v);
    return 0;
}
