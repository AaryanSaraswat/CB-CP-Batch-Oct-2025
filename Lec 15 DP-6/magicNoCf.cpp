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

int m,d;
string a,b;

int dp[2010][2][2][2010];

int f(int pos,int isTightL,int isTightR,int modVal){
    if(pos==sz(a)+1){
        if(modVal==0) return 1;
        return 0;

        // return (modVal==0);
    }

    if(dp[pos][isTightL][isTightR][modVal]!=-1) return dp[pos][isTightL][isTightR][modVal];

    int limitStart = isTightL ? (a[pos-1]-'0') : 0;
    int limitEnd = isTightR ? (b[pos-1]-'0') : 9;

    int ans  = 0;

    for(int digit = limitStart ; digit<=limitEnd ; digit++){

        int newTightL = isTightL && (digit==limitStart);
        int newTightR = isTightR && (digit==limitEnd);

        int newModVal = (modVal*10 + digit ) %m;

        if((pos&1) and (digit!=d)){
            ans = (ans + f(pos+1,newTightL,newTightR,newModVal)) % MOD;
        }
        else if(pos%2==0 and digit==d){
            ans = (ans + f(pos+1,newTightL,newTightR,newModVal)) % MOD;
        }
    }

    return dp[pos][isTightL][isTightR][modVal] = ans;
}

void solve(){
     cin>>m>>d;
     cin>>a>>b;


    memset(dp,-1,sizeof(dp));

    cout<<f(1,1,1,0)<<endl;
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
