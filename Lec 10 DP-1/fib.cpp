#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;

    // state : dp[i] = ith fobinaci no
    // trans: dp[i] = dp[i-1] + dp[i-2]
    // base case dp[0] = 0, dp[1] = 1
    // final ans dp[n]

    vector<int> dp(n+1,0);
    
    for(int i=2;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
    
    cout<<dp[n]<<endl;
    return 0;
}