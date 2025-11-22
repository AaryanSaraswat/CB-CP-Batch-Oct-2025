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
    int n; cin>>n;

    // state : dp[i] = no of ways to get i sum
    // transition : dp[i] = (dp[i-1],dp[i-2],......dp[i-6])
    // base : dp[0] = 1
    // final and dp[n]

    vector<int> dp(6,0);

    dp[0] = 1;

    for(int i=1;i<=n;i++){
        int sum = 0; 
        for(int k=0;k<6;k++){
            sum=(sum+dp[k]) % MOD;
        }
        dp[i%6] = sum;
    }

    // sc -> O(6) -> constant

    cout<<dp[n%6]<<endl;
    
    return 0;
}
