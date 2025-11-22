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

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (auto &r : a)
        for (auto &i : r)
            cin >> i;

    // 1023-->   10 bits
    bool f = 0;
    int chosenBitMask = -1;
    vector<int> res;
    for (int bit = 0; bit < 10; bit++)
    {
        vector<vp> b(n, vp(2, {-1, -1}));

        int bitMask = 1 << bit;
        loop(i, 0, n)
        {
            loop(j, 0, m)
            {
                bool f = (a[i][j] & bitMask);
                if (f)
                    b[i][1].fi = 1, b[i][1].si = j + 1;
                else
                    b[i][0].fi = 1, b[i][0].si = j + 1;
            }
        }
        vvi dp(n + 1, vi(2, -1));
        dp[n][0] = 0, dp[n][1] = 1;

        loopD(i, n - 1, 0)
        {
            if (b[i][1].fi != -1 and dp[i + 1][1] == 1)
                dp[i][0] = 1;
            else if (b[i][0].fi != -1 and dp[i + 1][0] == 1)
                dp[i][0] = 1;

            if (b[i][1].fi != -1 and dp[i + 1][0] == 1)
                dp[i][1] = 1;
            if (b[i][0].fi != -1 and dp[i + 1][1] == 1)
                dp[i][1] = 1;
        }

        if (dp[0][0] == 1)
        {
            f = 1;
            bool odd = 1;

            loop(i, 0, n)
            {
                if (odd) // odd uthana hai
                {
                    if (b[i][1].fi != -1 and dp[i + 1][1] == 1) // mere pass odd hai aur neeche tak even hai
                    {
                        res.pb(b[i][1].si);
                        odd = 0;
                    }
                    else
                    {
                        res.pb(b[i][0].si);
                    }
                }
                else
                {
                    if (b[i][1].fi != -1 and dp[i + 1][0] == 1) // mere pass odd hai aur neeche tak even hai
                    {
                        res.pb(b[i][1].si);
                        odd = 1;
                    }
                    else
                    {
                        res.pb(b[i][0].si);
                    }
                }
            }
            break;
        }
    }
  
    if (f)
    {
        cout << "TAK" << endl;
        for (int x : res)
            cout << x << ' ';
        cout << endl;
    }
    else
        cout << "NIE" << endl;

    return 0;
}