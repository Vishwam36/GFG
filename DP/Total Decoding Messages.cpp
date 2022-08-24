// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1#
// Easy

class Solution {
	public:
	    #define ll long long
	    ll const mod = 1e9 + 7;
	    vector<ll> dp;
	    
	    ll rec(int idx, string &str)
	    {
	        if(idx == str.size())
	            return 1;
	        
	        if(dp[idx] != -1)
	            return dp[idx];
	        
	        ll ans = 0;
	        if(str[idx] == '0')
	            return 0;
	        ans = (ans + rec(idx+1, str)) % mod;
	        if(idx+1 < str.size() && stoi(str.substr(idx, 2)) <= 26)
	            ans = (ans + rec(idx+2, str)) % mod;
	        
	        return dp[idx] = ans;
	    }
	    
		int CountWays(string str)
		{
		    dp.resize(str.size()+1, -1);
		    return rec(0, str);
		}

};
