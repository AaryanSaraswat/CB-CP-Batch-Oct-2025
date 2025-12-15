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

vvi adj;

bool isBipartite(int node,int currColor,vi &color){
    color[node] = currColor;
    int res = 1;
    for(auto ch:adj[node]){
        if(color[ch]==-1) res &= isBipartite(ch,1^currColor,color);
        else{ // already colored hai
            // kya same color to nahi h?
            if(color[ch]== currColor) return false;
        }
    }
    return res;
}

void solve(){
    int n; cin>>n;
    int m; cin>>m;
    adj.resize(n+1,vi());
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v; 
        // bidirectional
        adj[u].pb(v);
        adj[v].pb(u);

        // directed u->v
        // adj[u].pb(v);
    }

    vi color(n+1,-1);
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
