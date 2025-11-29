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

string K;
int D;

int dp[10010][2][101];

int f(int pos,int isTight,int sum){
    
    if(pos==sz(K)+1){
        if(sum==0) return 1;
        return 0;
    }

    if(dp[pos][isTight][sum]!=-1) return dp[pos][isTight][sum];

    int limit = isTight ? K[pos-1] - '0' : 9;

    int ans = 0;

    for(int digit  = 0; digit <=limit ; digit++){
        int newTight = isTight & (digit==limit);
        ans = (ans + f(pos+1, newTight, (sum+digit)%D)) % MOD;
    }

    return dp[pos][isTight][sum] = ans;
}

void solve(){
    cin>>K;
    cin>>D;
    memset(dp,-1,sizeof(dp));
     // subtract 1 because 0000 is not a valid state 
     cout<< (f(1,1,0) - 1 + MOD)  % MOD << endl;
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
