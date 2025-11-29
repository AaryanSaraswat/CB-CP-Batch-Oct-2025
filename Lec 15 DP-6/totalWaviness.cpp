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

class Solution
{
public:
    long long totalWaviness(long long num1, long long num2)
    {
        static pll dp[20][2][11][11];
        bool vis[20][2][11][11];

        auto f = [&](lli x)
        {
            
            string s = to_string(x);
            int n = sz(s);

            if (x < 100) return 0LL;
            
            loop(i,0,n+1) loop(t,0,2) loop(a,0,11) loop(b,0,11) vis[i][t][a][b] = false;

            auto ff = [&](auto self, int pos, int isTight, int v2, int v1) -> pll
            {
                if (pos == n) return {1, 0};

                if (vis[pos][isTight][v2][v1]) return dp[pos][isTight][v2][v1];

                vis[pos][isTight][v2][v1] = true;
                auto &ans = dp[pos][isTight][v2][v1];

                lli cnt = 0, sm = 0, limit = isTight ? (s[pos] - '0') : 9;

                loop(d,0,limit+1)
                {
                    int nv2=0, nv1=0;
                    if (v1 == 10 && d == 0) nv2 = nv1 = 10;
                    else
                    {
                        if (v1 == 10) nv2 = 10, nv1 = d;
                        else nv2 = v1,nv1 = d;
                    }
                    auto chotaAns = self(self, pos+1, isTight && (d == limit), nv2, nv1);
                    cnt += chotaAns.fi,sm += chotaAns.si + chotaAns.fi * ((v2 != 10 && v1 != 10) and ((v1 > v2 && v1 > d) || (v1 < v2 && v1 < d)));
                }
                return ans = {cnt, sm};;
            };

            return ff(ff, 0, 1, 10, 10).si;
        };

        return f(num2) - f(num1 - 1);
    }
};
