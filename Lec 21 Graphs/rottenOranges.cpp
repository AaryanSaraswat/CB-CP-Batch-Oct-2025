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

bool check(int i,int j,int n,int m, vvi& grid){
    return i>=0 and i<n and j>=0 and j<m and grid[i][j]==1;
}


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = sz(grid), m = sz(grid[0]),freshCnt = 0;
        queue<pii> q; // {i,j}
        int lvl  = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) freshCnt++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        vector<pii> directions = {{1,0},{0,1},{-1,0},{0,-1}};

        while (!q.empty())
        {
            int sq = sz(q);
            while (sq--)
            {
                auto [i,j] = q.front(); q.pop();

                for(auto &[di,dj] : directions){
                    int ni = i+di , nj = j+dj;
                    // out of bound
                    if(check(ni,nj,n,m,grid)){
                        q.push({ni,nj});
                        grid[ni][nj]=2; // vis mark
                        freshCnt--;
                    }
                }
            }
            lvl++; // minutes++
        }
        
        if(freshCnt==0) return lvl==0?0:lvl-1;
        return -1;
    }
};