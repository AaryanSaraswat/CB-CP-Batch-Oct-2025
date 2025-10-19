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

vi spfCalc(int n) // O(n*loglogn)
{
    vi spf(n + 1, 1);
    // every spf[i] = i;
    for(int i=0;i<=n;i++) spf[i]=i;
    for (int i = 2; i * i <= n; i++) // till root n
    {
        if (spf[i]==i) // ye no prime hai
        {
            for (int j = i * i; j <= n; j += i) // itertate on multiples
                if(spf[j]==j) spf[j] = i; // tera spf mein hu
        }
    }
    return spf;
}

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int mx = *max_element(all(nums));
        vi spf = spfCalc(mx);
        unordered_set<int> allFactors;
        for(auto &no:nums){
            while(no!=1){
                allFactors.insert(spf[no]);
                no/=spf[no];
            }
            cout<<endl;
        }
        return sz(allFactors);
    }
};