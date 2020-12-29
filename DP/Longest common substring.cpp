// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/longest-common-substring/0#
// try building matrix you will surely understand

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t=0,n=0,m=0,ans=0;
    string s1,s2;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        cin>>s1>>s2;
        
        int a[n+1][m+1];
        memset(a,0,sizeof(a));
    
	    for(int i=1;i<=n;++i)
	    {
	        for(int j=1;j<=m;++j)
	        {
	            if(s1[i-1] == s2[j-1])
	            {
	                a[i][j] = a[i-1][j-1] + 1;
	                
	                if(ans < a[i][j])
	                {
	                    ans = a[i-1][j-1] + 1;
	                }
	            }
	        }
	    }
	    cout<<ans<<endl;
    }
	  return 0;
}
