// By Vishwam Mundada
// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0#
// Tricky question

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // blockSum = amount of space covered by blocks
    // blockAndWaterSum = amount of space covered by block and water collectively
    
    int t = 0, n = 0, maxx = 0, blockSum = 0, blockAndWaterSum = 0;
    cin >> t;
    while(t--)
    {
        blockSum = 0;
        blockAndWaterSum = 0;
        
        cin >> n;
        int a[n], l[n], r[n], minLR[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            blockSum += a[i];
        }
        
        maxx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(a[i] > maxx)
            {
                maxx = a[i];
            }
            l[i] = maxx;
        }
        
        maxx = 0;
        for(int i = n-1; i >= 0; --i)
        {
            if(a[i] > maxx)
            {
                maxx = a[i];
            }
            r[i] = maxx;
        }
        
        for(int i = 0; i < n; ++i)
        {
            minLR[i] = min(l[i], r[i]);
            blockAndWaterSum += minLR[i];
        }
        
        cout << blockAndWaterSum - blockSum << endl;
    }
	return 0;
}
