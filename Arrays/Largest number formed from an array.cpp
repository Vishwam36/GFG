// By vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1#

#include <bits/stdc++.h>

using namespace std;

bool cmp(string s1, string s2)
{
    string t1 = s1 + s2;
    string t2 = s2 + s1;
    return t1 > t2;
}

class Solution{
public:

	string printLargest(vector<string> &arr) 
	{
	   string s;
	   sort(arr.begin(), arr.end(), cmp);
	   for(int i = 0; i < arr.size(); ++i)
	   {
	       s += arr[i];
	   }
	   return s;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
