// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#
// IMP, easy

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n)
    {
        int max_sum = 0, sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if(sum < 0)
                sum = 0;
            
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};
