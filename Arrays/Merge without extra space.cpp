// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#

#include <bits/stdc++.h> 
using namespace std; 

// compare largest element of arr1 with smallest element of arr2
// then compare next smaalest of arr1 with next smallest of arr2
// at the end of this process we will have first n small elements in arr1 and next in arr2
// then just sort arr1 and arr2

void merge(int arr1[], int arr2[], int n, int m) 
{
    int i=n-1, j=0;
    while(i>=0 && j<m)
    {
        if(arr1[i]>arr2[j])
        {
            swap(arr1[i],arr2[j]);
            --i;
            ++j;
        }
        else
        {
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
	    for (int i = 0; i < m; i++) 
		    printf("%d ", arr2[i]); 
	    
	    cout<<endl;
	}

	return 0; 
}
