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

void solve(){
    int n,k; cin>>n>>k;
    vi a(n);
    for(auto &i:a) cin>>i;

    // state: dp[i] -> with k stones, can current player win? -> T/F
    // transition: dp[i] = T (if any dp[i-a] -> F)
    // base case dp[i] = 0 (i<min(a)) and dp[i] = T if(i==aj)
    // final ans dp[k]-> T(Taro) F(Jiro)

    vi dp(k+1,0);

    int mn = 1e18;
    // base 
    for(auto i:a) dp[i] = 1,mn=min(mn,i);

    for(int i=mn+1;i<=k;i++){
        for(auto &el:a){
            if(i-el>=0){
                if(dp[i-el]==0) dp[i]= 1;
            }
        }
    } 

    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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
