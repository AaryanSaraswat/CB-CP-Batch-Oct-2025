#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define present(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
#define int long long

typedef long long lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

void solve(){
    int n,cap;
    cin>>n>>cap;

    vi weight(n+1),value(n+1);

    for(int i=1;i<=n;i++) cin>>weight[i]>>value[i];

    // state : dp[i][v] -> i elements m se v val lane k liye min weight
    // transition: 
        // dp[i][v] = min(dp[i-1][v], dp[i-1][v-vali]+wi)
    // base case dp[i][0] = 0, dp[0][v] = 1e9
    // final ans dp[i][v] = w w<=cap v->max
    int mxVal = *max_element(all(value))*n;
    vvi dp(n+1,vi(mxVal+1,0));

    // base case
    // dp[0][0] -> ?
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int val=1;val<=mxVal;val++) dp[0][val] = 1e9;

    for(int i=1;i<=n;i++){
        for(int val=1;val<=mxVal;val++){
            int pick=1e9, notPick = dp[i-1][val];
            if(val-value[i]>=0) 
                pick = dp[i-1][val-value[i]] + weight[i];
            dp[i][val]= min(pick,notPick);
        }
    }


    // final ans
    int ans = 0;

    loop(val,0,mxVal+1){
        if(dp[n][val]<=cap) ans=max(ans,val);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
