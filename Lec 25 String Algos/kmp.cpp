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

vi computeLPS(string &ptr){
    int m = size(ptr), len  = 0, i = 1;
    vi lps(m);
    lps[0] =  0;
    
    while(i<m){
        if(ptr[i]==ptr[len]){ //compare ith and len th character
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len==0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
    return lps;
}

void KMP(string &txt, string &ptr){
    auto lps = computeLPS(ptr);
    int i = 0, j = 0 , n = sz(txt), m=sz(ptr);
    vi ans; // occurences of ptr in txt
    while (i<n)
    {
        if(txt[i] == ptr[j]){
            i++,j++;
            if(j==m){ // found
                ans.pb(i-m); // collect the starting points
                // update j ?
                j = lps[j-1];
            }
        }
        else if(ptr[j]!=txt[i]){
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
    
}

void solve(){
    string txt, ptr; cin>>txt>>ptr;
}

int32_t main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        
    }
    return 0;
}
