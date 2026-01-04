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

struct DSU{
    vi p,rank,size;
    int components=0;
    DSU(int n):p(n,0),rank(n,0),components(n),size(n,1){ iota(all(p),0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool inSameSet(int u,int v){ return find(u)==find(v); }
    void join(int u,int v){ if(!inSameSet(u,v)){ u=find(u),v=find(v); components--; if(rank[u]>rank[v]) p[v]=u; else{ p[u]=v; rank[v]+=(rank[u]==rank[v]);} } }
    void joinBySz(int u,int v){ if(!inSameSet(u,v)){ u=find(u),v=find(v); components--; if (size[u] < size[v]) swap(u, v); p[v] = u, size[u] += size[v]; } }
    int noOfConnectedComponents(){ return components; }
    int getSize(int x) { return size[find(x)]; }
};

void solve(){
    int n; cin>>n;
    int m; cin>>m;

    vector<vp> adj(n+1);

    // node -> ch
    // node -> {ch1,w1} , {ch2, w2}
    DSU dsu(n);
    vvi edges;

    for(int i=0;i<m;i++){
        // u v w
        int u,v,w; cin>>u>>v>>w;
        edges.pb({w,u,v}); // {w,u,v}
    }

    sort(all(edges));

    int sum = 0, cnt = 0, i=0;

    while (cnt!=n-1 and i<m)    
    {
        auto vec = edges[i];
        int w  = vec[0], u = vec[1], v= vec[2];

        // only take this egde if there is no cycle
        int rootu = dsu.find(u), rootv = dsu.find(v);
        if(rootu!=rootv){ // cycle nahi hai
            sum+=w;
            adj[u].pb({v,w}); 
            adj[v].pb({u,w});
            dsu.join(u,v);
            cnt++;
        }
        i++;
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
