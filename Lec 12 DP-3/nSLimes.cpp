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
    int n; cin>>n;

    vi a(n); for(auto &i:a) cin>>i;

    // state: dp[i][j] -> min cost to add slimes btwn i & j 
    // transition : dp[i][j] = min(dp[i][k]+dp[k+1][j]+sum(i,j)) for all 1<k<n-2
    // base case i==j dp[i][j] = 0, i>j -> handle
    // final ans = dp[0][n-1]

    vi pre(n,0); // 0-based
    pre[0]=a[0];
    loop(i,1,n) pre[i]= pre[i-1]+a[i];

    auto sum=[&](int i,int j){
        return pre[j] - ((i-1>=0) ? pre[i-1]:0);
    };

    vvi dp(n,vi(n,1e18));

    // base case
    // this should be 0 as cost to add 1 element is 0 not itself 
    loop(i,0,n) dp[i][i]= 0;

    //  i-> n-1 - 0
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j;k++){
                // dp[i][j] - > dp[i][k] dp[k+1][j]
                int currCost = dp[i][k] + dp[k+1][j] + sum(i,j);
                dp[i][j] = min(dp[i][j],currCost);
            }
        }
    }

    // final ans
    cout<<dp[0][n-1]<<endl;

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
