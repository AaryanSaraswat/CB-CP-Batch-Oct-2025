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

class DSU{
    vi parent,rank;
    public:

    DSU(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        // har kisi node ka parent use khud bnana hoga
        for(int i=0;i<=n;i++) parent[i] = i;

        // iota(all(parent),0);
        // iota(parent.begin(),parent.end(),0);
        // [0,1,2,3,4,5]
    }

    int find(int x){ // finds abs par / root of set
        if(parent[x]==x) return x;

        return find(parent[x]);
    }

    void join(int u,int v){
        int rootu = find(u);
        int rootv = find(v);

        if(rootu==rootv) return;

        if(rank[rootu]>rank[rootv]) swap(rootu,rootv);
        parent[rootu] = rootv;
        if(rank[rootu]== rank[rootv]) rank[rootv] ++;
    }
};

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
