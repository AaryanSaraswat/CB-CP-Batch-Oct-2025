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

vector<vector<int>> adj;
vector<vector<int>> dp; 
// dp[node][x] -> 2^xth parent of node

void dfs(int node,int parent){

    // processing -> precomputing dp
    // base case
    dp[node][0] = parent;
    for(int x=1;x<18;x++) 
        dp[node][x] = dp[dp[node][x-1]][x-1];

    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node);
    }
}

int kthParent(int node, int k){ // O(log(k))
    for(int bits=17;bits>=0;bits--){
        // set bit
        int mask = (1<<bits);
        if(k&mask){
            node = dp[node][bits];
        }
    }
    return node;
}

void solve(){
    int n; cin>>n;
    adj.resize(n+1);
    dp.resize(n+1,vi(18,0));

    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,0);

    cout<<kthParent(6,2)<<endl;
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
