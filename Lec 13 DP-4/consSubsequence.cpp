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

void solve()
{
    int n; cin>>n;

    vi a(n+1,0); loop(i,1,n+1) cin>>a[i];

    unordered_map<int,int> dp;

    int lastIndex = -1, len =0, val;

    for(int i=1;i<=n;i++){
        int x = a[i];
        dp[x] = max(dp[x-1]+1,dp[x]);

        if(dp[x]>len){
            len = dp[x], lastIndex = i;
            val =x;
        }
    }

    cout<<len<< endl;

    // ans construct

    vi path;

    for(int i=lastIndex;i>=1;i--){
        int x = a[i];
        if(x==val){
            path.pb(i);
            val--,len--;
        }
    }

    reverse(all(path));
    for(auto &i:path) cout<<i<<" "; 
    cout<<endl;
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
