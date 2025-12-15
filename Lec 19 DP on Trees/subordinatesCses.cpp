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
vi ans;

void dfs(int node,int parent){
    int cnt=0;

    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node);
        cnt += ans[ch] + 1;
    }

    ans[node]= cnt;
}

int dfs2(int node,int parent){
    int cnt=0;

    for(auto ch:adj[node]){
        if(ch==parent) continue;
        cnt += dfs2(ch,node) + 1;
    }

    return ans[node]= cnt;
}

void solve(){
    int n; cin>>n;

    adj.resize(n+1,vi());
    ans.resize(n+1,0);

    for(int u=2;u<=n;u++){
        int v; cin>>v;
        // edge between u and v
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,0);

    for(int node=1;node<=n;node++) cout<<ans[node]<<" ";
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
