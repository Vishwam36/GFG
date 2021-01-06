// By Vishwam Shriram Mundada
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#
// simple logic
// when price is going to increase in future buy the stock
// and when price is going to decrease in future sell the stock
// handle the end index case

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int n)
    {
        vector<vector<int> > v;
        vector<int> temp;
        int buy = -1, sell = -1;
        bool bought = false;
        for(int i = 0; i < n-1; ++i)
        {
            if(buy != -1 && sell != -1)
            {
                temp.clear();
                temp.push_back(buy);
                temp.push_back(sell);
                v.push_back(temp);
                buy = -1;
                sell = -1;
                bought = false;
                temp.clear();
            }
            if(A[i+1] > A[i] && bought == false)
            {
                buy = i;
                bought = true;
            }
            else if(A[i+1] < A[i] && bought == true)
            {
                sell = i;
                bought = false;
            }
            if(i == n-2)
            {
                if(bought == true && A[n-1] >= A[n-2])
                {
                    sell = n-1;
                    bought == false;
                }
            }
        }
        if(buy != -1 && sell != -1)
        {
            temp.push_back(buy);
            temp.push_back(sell);
            v.push_back(temp);
        }
        return v;
    }
};

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            for (int i=0; i<ans.size(); ++i){
                cout<<"("<<ans[i][0]<<" "<<ans[i][1]<<") ";
            }
        }cout<<endl;
    }
    return 0;
}
