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
vi subAns,cnt,ans;

void dfs(int node,int parent){
    cnt[node]=1;
    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node);
        subAns[node] += (subAns[ch]+cnt[ch]);
        cnt[node] += cnt[ch];
    }
}

void remove(int node,int ch){
    subAns[node] -= (subAns[ch]+cnt[ch]);
    cnt[node] -= cnt[ch];
}

void add(int node,int ch){
    subAns[node] += (subAns[ch]+cnt[ch]);
    cnt[node] += cnt[ch];
}

void reRoot(int node,int ch){
    remove(node,ch); // 1(NODE) 2(ch)
    // middle state
    add(ch,node); // 1(NODE) 2(ch)
}

void dfs2(int node,int parent){ // 1 0
    ans[node] = subAns[node];
    for(auto ch:adj[node]){ // 1 -> 2,3
        if(ch==parent) continue;
        reRoot(node,ch); // 1(NODE) 2(ch)
        dfs2(ch,node);
        // backTrack
        reRoot(ch,node);
    }
}

void solve(){
    int n; cin>>n;

    adj.resize(n+1,vi());
    subAns.resize(n+1,0);
    ans.resize(n+1,0);
    cnt.resize(n+1,0);

    for(int i=1;i<=n-1;i++){
        int v; cin>>v;
        int u; cin>>u;
        // edge between u and v
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,0);
    dfs2(1,0);

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
