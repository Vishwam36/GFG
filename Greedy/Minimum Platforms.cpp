// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
// Easy, little trick

/*
minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) 
and the last two characters represent minutes (between 00 to 59).

Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 50000
0000 <= A[i] < D[i] <= 2359
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        if(n <= 1)
            return n;
        
        vector<pair<int, char> > v;
        for(int i = 0; i < n; ++i)
        {
            v.push_back({arr[i], 'a'});
            v.push_back({dep[i], 'd'});
        }
        sort(v.begin(), v.end());
        
    	int plats = 0, ans = 0;
    	for(int i = 0; i < v.size(); ++i)
    	    if(v[i].second == 'a')
    	        ans = max(ans, ++plats);
    	    else
    	        --plats;
    	
    	return ans;
    }
};
