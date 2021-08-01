// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1#
// Easy

/*
Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s for any prefix of the number.

Example 1:
Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than 
or equal 1's than 0's

Example 2:
Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's

User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of strings in decreasing order. You need not take any 
input or print anything.

Expected Time Complexity: O(|2^N|)
Expected Auxiliary Space: O(2^N)

Constraints:
1 <= N <= 20
*/

class Solution{
public:
    vector<string> ans;
    
    void rec(string &temp, int zeros, int ones, int n)
    {
        if(zeros+ones == n)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('1');
        rec(temp, zeros, ones+1, n);
        temp.pop_back();
        
        if(zeros < ones)
        {
            temp.push_back('0');
            rec(temp, zeros+1, ones, n);
            temp.pop_back();
        }
    }
    
	vector<string> NBitBinary(int n)
	{
	    string temp = "";
	    rec(temp, 0, 0, n);
	    return ans;
	}
};
