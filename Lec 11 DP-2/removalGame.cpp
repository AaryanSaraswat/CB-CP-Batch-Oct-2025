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
    vi a(n);
    for(auto &i:a) cin>>i;

    vvi dp(n+1,vi(n+1,0));
    
    // state : dp[i][j] -> max score a player can get btwm i and j
    // transition :
    // dp[i][j]= max(ai + sumi+1j - dp[i+1][j],
                //   aj + sumij-1 - dp[i][j-1]);

    // base case i==j a[i], i>j 0
    // final ans dp[0][n-1]

    vi pre(n,0); // 0-based
    pre[0]=a[0];
    loop(i,1,n) pre[i]= pre[i-1]+a[i];

    auto sum=[&](int i,int j){
        return pre[j] - ((i-1>=0) ? pre[i-1]:0);
    };

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i>j) continue;
            if(i==j) dp[i][j] = a[i];
            else{
                // transition
                dp[i][j]= max(a[i] + sum(i+1,j) - dp[i+1][j],
                  a[j] + sum(i,j-1) - dp[i][j-1]);
            }
        }
    }

    //final ans
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
