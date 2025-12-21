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

vector<vector<pii>> adj;
int n;

vi dijkstra(int src){
    vi dist(n+1,INT_MAX);

    priority_queue<pii,vector<pii>,greater<pii>> pq; // min-heap // {dist[node],node}
    dist[src] = 0; pq.push({dist[src],src});

    while(!pq.empty()){
        auto [d,node] = pq.top(); pq.pop();
        if( d > dist[node]) continue;  // save iterations
        for(auto [ch,ew]: adj[node]){
            if(dist[node]+ ew < dist[ch]){
                dist[ch] = dist[node] + ew ;
                pq.push({dist[ch],ch});
            }
        }
    }
    return dist;
}

int shortestPath(int src,int des, vvi &edges){
    vi d1 = dijkstra(src);
    vi d2 = dijkstra(des);

    int ans =  1e18;

    for(auto edge:edges){
        int a = edge[0], b = edge[1], w= edge[2];

        int op1  = d1[a] + w/2 + d2[b];
        int op2  = d1[b] + w/2 + d2[a];

        ans= min({ans,op1,op2});
    }

    return ans;

}

void solve(){
    cin>>n;
    adj.assign(n+1,{});

    vvi edges;

    int m; cin>>m;
    loop(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});

        edges.pb({u,v,w});
        // adj[v].pb({u,w});
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
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
