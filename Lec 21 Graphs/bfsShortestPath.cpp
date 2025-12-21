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

bool check(int i,int j,int n,int m, vvi& vis){
    return i>=0 and i<n and j>=0 and j<m and vis[i][j]==0;
}

int shortestPath(vvi &grid, pii src, pii des){
    int n= sz(grid), m = sz(grid[0]);

    queue<vi> q; // { i, j , dist}
    vvi vis(n+1,vi(m+1,0));

    q.push({src.first , src.second , 0}); vis[src.fi][src.si] = 1;

    vector<pii> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    while (!q.empty())
    {
        auto &v = q.front(); q.pop();
        int i = v[0], j= v[1], dist = v[2];

        // if i had reached destination
        if(i==des.fi and j==des.si) return dist;

        for(auto &[di,dj] : directions){
            int ni = i+di , nj = j+dj;
            // out of bound
            if(check(ni,nj,n,m,vis)){
                q.push({ni,nj,dist+1});
                vis[ni][nj]=1;
            }
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
