// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/ncr1019/1#
// Good question

// App 1 : Inverse factorial
// TC : O(N)
// SC : O(N)

class Solution{
public:
    long long MOD = 1000000007;
    
    long long myPow(long long a, long long p)
    {
        if(p == 0)
            return 1;
        
        if(p == 1)
            return a;
        
        if(p % 2 == 0)
        {
            long long ans = myPow(a, p/2) % MOD;
            return (ans*ans) % MOD;
        }
        else
        {
            long long ans = myPow(a, p/2) % MOD;
            return (((ans * ans) % MOD) * a) % MOD;
        }
    }

    int nCr(int n, int r)
    {
        if(n < r)
            return 0;
        
        long long fact[n+1];
        fact[0] = 1;
        for(int i = 1; i <= n; ++i)
            fact[i] = (fact[i-1] * i) % MOD;
        
        long long invFact_r = myPow(fact[r], MOD-2); // inverse of fact[r]
        long long invFact_n_r = myPow(fact[n-r], MOD-2); // inverse of fact[n-r]
        
        return (((fact[n] * invFact_r) % MOD) * invFact_n_r) % MOD;
    }
};

// Pascals Triangle approach
// TC : O(N*R)
// SC : O(R)
// REF : https://www.youtube.com/watch?v=jIb1W3ObIho

class Solution{
public:
    int nCr(int n, int r)
    {
        if(n < r)
            return 0;
        
        if(r > n-r)
            r = n-r;
        
        int MOD = 1000000007;
        vector<int> dp(r+1, 0);
        dp[0] = 1;
        
        // building rows of pascals triangle one by one
        for(int i = 1; i <= n; ++i)
            for(int j = min(i, r); j > 0; --j)
                dp[j] = (dp[j] + dp[j-1]) % MOD;
        
        return dp[r];
    }
};
