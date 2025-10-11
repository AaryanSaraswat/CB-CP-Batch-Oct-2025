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

bool f(vi &ropes,double len,int k){
    int cnt = 0;
    for(auto &rope:ropes){
        cnt += (rope/len);
    }
    return cnt>=k;
}

void solve(){
    int n,k; cin>>n>>k;
    vi ropes(n); 
    double st = 0.0, en = 0.0, ans = 0.0;
    for(auto &i: ropes) cin>>i ,en+=i;

    double precision = (1e-7);

    while(en-st>precision){
            double mid  = (st)+(en-st)/2;
            if(f(ropes,mid,k)) ans = mid , st = mid + precision;
            else en = mid - precision;
    }
    cout<< setprecision(7) << ans<<endl; 
    // this will print only upto 7 decimal places
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
