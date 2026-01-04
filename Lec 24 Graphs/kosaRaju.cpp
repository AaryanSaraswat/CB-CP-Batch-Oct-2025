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

void dfs(int node, vi &vis, vvi &adj, vi &order){
    vis[node] = 1;
    for(auto ch:adj[node]){
        if(!vis[ch]) dfs(ch,vis,adj,order);
    }
    order.pb(node);
}

void solve(){
    int n,m; cin>>n>>m;

    vvi adj(n+1,vi()),radj(n+1,vi()),adj_cond(n+1,vi());

    loop(i,0,m){
        int u, v; cin>>u>>v; 
        // u ->v
        adj[u].pb(v);
        // step 2
        radj[v].pb(u);
    }


    // step 1
    vi order,vis(n+1,0);

    for(int node=1;node<=n;node++) 
        if(!vis[node]) dfs(node,vis,adj,order);

    reverse(all(order));

    // step 3

    vvi SCC;
    vis.clear();
    vis.resize(n+1,0);

    vi leader(n+1,0);

    for(auto node:order){
        if(vis[node]) continue;
        vi currentComponent;
        dfs(node,vis,radj,currentComponent);
        SCC.pb(currentComponent);
        // int lead = node;
        int lead = currentComponent[0];
        for(auto ch:currentComponent) leader[ch] = lead;
    }

    for(int node=1;node<=n;node++){
        for(auto ch:adj[node]){
            if(leader[node]!=leader[ch]) 
                adj_cond[leader[node]].pb(leader[ch]);
        }
    }

}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        
    }
    return 0;
}

