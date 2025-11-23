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

int n;
vvi a;

// dp
vi dp;

int f(int vis){

    int currMan = set_bits(vis) + 1; // __builtin_popcountll()
    
    // base case
    if(currMan==n+1) return 1;

    // calculate se phle check
    if(dp[vis]!=-1) return dp[vis];


    // recursive case
    int ans = 0;

    for(int woman = 1 ; woman<=n ; woman++){
        //1. comptability 
        if(a[currMan][woman]==0) continue;
        //2. availability -> check curr bit
        int mask = (1<<woman);
        if(vis&mask) continue; // already visited
        ans = (ans+f(vis|mask)) % MOD;  // by value
    }
    return dp[vis] = ans;
}


void solve(){
    cin>>n;

    a.resize(n+1,vi(n+1,0));

    int mxn = (1<<(n+1)) +1;
    dp.resize(mxn,-1);

    loop(i,1,n+1) loop(j,1,n+1) cin>>a[i][j];

    cout<<f(0)<<endl;

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
