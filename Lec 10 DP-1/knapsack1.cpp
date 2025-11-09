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

    vvi dp(n+1,vi(cap+1));

    // state: dp[i][c] = max value we can get from i elements with c capacity
    // transition : dp[i][c] = max(dp[i-1][c-w]+val,dp[i-1][c])
    // base case : dp[i][0] = 0 , dp[0][c] =0;
    // final ans : dp[n][cap]

    for(int i=1;i<=n;i++) dp[i][0] =0;
    for(int c=0;c<=cap;c++) dp[0][c] =0;

    for(int i=1;i<=n;i++){
        for(int c=1;c<=cap;c++){
            // not pick 
            dp[i][c] = dp[i-1][c];

            //pick 
            int newCap = c-weight[i];
            if(newCap>=0) 
                dp[i][c]= max(dp[i-1][newCap]+value[i],dp[i][c]);
        }
    }
    // final ans
    cout<<dp[n][cap]<<endl;
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
