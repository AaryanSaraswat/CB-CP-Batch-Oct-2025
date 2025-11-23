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

int a[20];
int n,m,k;
map<pii,int> mp;

// dp -> currDishNo vis lastDish
// int dp[][][];

const int maxn = (1<<(20));

int dp[20][maxn][20];

int f(int currDish,int vis,int lastDish){

    if(currDish==m+1) return 0;

    if(dp[currDish][vis][lastDish]!=-1) return dp[currDish][vis][lastDish];

    int ans = 0;
    for(int dish =1;dish<=n;dish++){
        // 1. not visited
        int mask = (1<<dish);
        if(vis&mask) continue;
        int extra = mp[{lastDish,dish}];
        int currAns = f(currDish+1,vis|mask,dish) + a[dish] + extra;

        ans=max(ans,currAns);
    }
    return dp[currDish][vis][lastDish] = ans;
}

void solve(){
     cin>>n>>m>>k;

    for(int i=1;i<=n;i++) cin>>a[i];

    loop(i,0,k){
        int x,y,c; cin>>x>>y>>c;
        mp[{x,y}] = c;
    }

    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(maxn,vector<int>(n+1,-1)));

    memset(dp,-1,sizeof(dp)); // -1 0 1

    cout<<f(1,0,0)<<endl; // default value for last dish which is not btwn 1<=n
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
