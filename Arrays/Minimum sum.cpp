// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-sum4058/1#
// Easy

/*
Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. 
All digits in the given array must be used to form the two numbers.

Example 1:
Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.


Example 2:
Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

Your Task:
You don't need to read input or print anything. Your task is to complete the function solve() which takes arr[] and n as input parameters and 
returns the minimum possible sum. As the number can be large, return string presentation of the number without leading zeroes.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 107
0 ≤ Arri ≤ 9
*/

class Solution{   
public:
    string solve(int arr[], int n) 
    {
        sort(arr, arr+n);
        string sum;
        int i = n-1, carry = 0;
        
        while(i > 0)
        {
            int num = arr[i]+arr[i-1]+carry;
            carry = num/10;
            sum += to_string(num%10);
            i-=2;
        }
        if(i == 0)
        {
            int num = arr[i]+carry;
            carry = num/10;
            sum += to_string(num%10);
        }
        
        while(carry)
        {
            int num = carry;
            carry = num/10;
            sum += to_string(num%10);
        }
        
        reverse(sum.begin(), sum.end());
        while(sum[0] == '0')
            sum.erase(sum.begin());
        
        return sum;
    }
};
