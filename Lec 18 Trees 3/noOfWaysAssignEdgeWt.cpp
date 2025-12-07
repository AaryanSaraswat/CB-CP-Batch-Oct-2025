#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
// #define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define pansent(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
// #define int long long

typedef long long lli;
typedef long long ll;
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
vi level;

void dfs(int node,int parent,int lvl){
    // processing -> precomputing dp
    level[node] = lvl;
    // base case
    dp[node][0] = parent;
    for(int x=1;x<18;x++) 
        dp[node][x] = dp[dp[node][x-1]][x-1];

    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node,lvl+1);
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

int lca(int a,int b){ // log(n)
    // step 1 -> to get them at same level
    if(level[a]>level[b]) swap(a,b);
    int k = level[b]- level[a];
    b = kthParent(b,k);

    if(a==b) return a;

    // step 2 iterate on 2^xth parents
    for(int x=17;x>=0;x--){
        if(dp[a][x]!=dp[b][x]) a= dp[a][x], b= dp[b][x];
    }

    // lca 
    return dp[a][0]; // direct parent of a
}

int dist(int a,int b){
    return level[a] + level[b] - 2*level[lca(a,b)];
}

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int halfPow = power(a, b / 2);
    if (b & 1) // odd hai to
        return halfPow * halfPow * a;
    return halfPow * halfPow;
}

ll power(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    if(a>m) a %= m;
    ll halfPow = power(a, b / 2, m);
    ll result = halfPow * halfPow % m;
    if (b & 1) // if b is odd
        result = result * a % m;
    return result;
}

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = sz(edges) + 1;

        adj.clear();
        level.clear();
        dp.clear();

        adj.resize(n+1);
        level.resize(n+1,0);
        dp.resize(n+1,vi(18,0));

        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1,0,0);
        vi ans;
        for(auto q:queries)
        {
            int a =q[0], b = q[1];
            int d  = dist(a,b);
            if(d==0){
                ans.push_back(0);
            }
            else ans.push_back(power(2,d-1,MOD));
        }
        return ans;
    }
};