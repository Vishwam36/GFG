// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
// Solved by using Selective Quick Sort

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{   
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

int partition(int arr[], int l, int r)
{
    // Randomized Quick Sort 
    int random = l + rand() % (r-l);
    swap(arr[random], arr[r]);
    
    int pIndex = l, i = l, pivot = arr[r];
    
    for(i = l; i < r; ++i)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            ++pIndex;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quicksort(int arr[], int l, int r, int k)
{
    if(l >= r)
        return;
        
    int pivotIndex = partition(arr,l,r);
    
    // if element on k-1 th position is found then return element
    if(pivotIndex == k-1)
        return;
    
    // if pivot was not in first k elemnts then recur in left subarray
    else if(pivotIndex > k-1)
        quicksort(arr, l, pivotIndex-1, k);
        
    // else if pivot is found in first k-1 elements then recur in right subarray
    else
        quicksort(arr, pivotIndex+1, r, k);
}

int kthSmallest(int arr[], int l, int r, int k) 
{
    quicksort(arr,l,r,k);
    
    return arr[k-1];
}
