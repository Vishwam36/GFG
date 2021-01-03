// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

long long cnt = 0;

void merge(long long arr[], long long l, long long m, long long r)
{
    long long nL = m-l+1;
    long long nR = r-m;
    
    long long left[nL];
    long long right[nR];
    
    for(long long i=0 ;i<nL; ++i)
        left[i] = arr[l+i];
        
    for(long long i=0 ;i<nR; ++i)
        right[i] = arr[m+1+i];
        
    long long i=0, j=0, k=l;
    
    while(i<nL && j<nR)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            ++i;
        }
        else
        {
            arr[k] = right[j];
            ++j;
            
            // The only extra step other than merge sort
            cnt += nL-i;
        }
        ++k;
    }
    while(i < nL)
    {
        arr[k] = left[i];
        ++i;
        ++k;
        //cnt += 
    }
    while(j < nR)
    {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

void mergesort(long long arr[], long long l, long long r)
{
    if(l >= r)
        return;
        
    long long m = (r+l-1)/2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
}

long long int inversionCount(long long arr[], long long N)
{
    cnt = 0;
    mergesort(arr, 0, N-1);
    return cnt;
}

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    return 0;
}
