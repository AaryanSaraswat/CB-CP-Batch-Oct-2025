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


int power(int a, int b)
{
    if (b == 0)
        return 1;

    int halfPow = power(a, b / 2);
    if (b & 1) // odd hai to
        return halfPow * halfPow * a;
    return halfPow * halfPow;
}

int power(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (a > m)
        a %= m;
    int halfPow = power(a, b / 2, m);
    int result = halfPow * halfPow % m;
    if (b & 1) // if b is odd
        result = result * a % m;
    return result;
}

void solve()
{
    int n, k;
    string s;
    cin >> s;
    n=sz(s);

    vi fact(n + 1), inv_fact(n + 1);
    fact[0]= fact[1] = 1;
    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;

    inv_fact[n] = power(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] % MOD * (i + 1) % MOD) % MOD;

    unordered_map<char,int> freq; 
    for(auto &c:s) freq[c]++;

    int ans = fact[n];
    // for(auto p:freq)
    //     ans/=inv_fact[p.second];
    for(auto &[ch,fr]:freq)
        ans = (ans * inv_fact[fr]) % MOD;
    
    cout<<ans<<endl;
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
