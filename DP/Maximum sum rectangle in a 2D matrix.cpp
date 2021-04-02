// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0#
// Ref : https://www.youtube.com/watch?v=kKEX4P53MyY&ab_channel=CodeLibrary
// Decent

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &v)
{
    int maxSum = INT_MIN, tempSum = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        tempSum += v[i];
        
        if(maxSum < tempSum)
            maxSum = tempSum;
        
        if(tempSum < 0)
            tempSum = 0;
    }
    return maxSum;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int r = 0, c = 0, maxSum = INT_MIN;
        cin >> r >> c;
        vector<vector<int> > v(r, vector<int> (c, 0));
        
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                cin >> v[i][j];
        
        for(int i = 0; i < r; ++i)
        {
            vector<int> sum(c);
            for(int j = i; j < r; ++j)
            {
                for(int col = 0; col < c; ++col)
                {
                    sum[col] += v[j][col];
                }
                maxSum = max(maxSum, kadane(sum));
            }
        }
        cout << maxSum << endl;
    }
	return 0;
}
