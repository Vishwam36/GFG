// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0#

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int ans = 0, t = 0, n = 0;
    string s;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        ans = 0;
        cin >> s;
        n = s.size();
        for(int j = 0; j < n; ++j)
        {
            vector<bool> v(256);
            for(int k = j; k < n; ++k)
            {
                if(v[s[k]] == true)
                {
                    break;
                }
                else
                {
                    v[s[k]] = true;
                    ans = max(ans, k-j+1);
                }
            }
        }
        cout << ans << endl;
    }
	  return 0;
}
