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

string transform(string &s){
    string t = "#";
    for(auto &c:s){
        t+=c;
        t+='#';
    }
    return t;
}

vi p;

int getLongest(int centre, bool odd){ // O(1)
    int pos = 2*centre + 1  + (!odd); // !odd -> even pos
    return p[pos] - 1;
}

bool checkPal(int l,int r){ // O(1)
    // mid -> getLongest >= (dist l,r) -> T else F
    int mid  = (l+r) / 2;
    int len = r-l+1;
    return len <= getLongest(mid, l%2==r%2 );
}

void manachers(string &s){ // O(n)
    // step 1 -> transform
    string t = transform(s);
    int n = sz(t);
    p.resize(n+1,1);
    // p[0] = 1;

    int l = 1, r = 1;
    for(int i=1;i<n;i++){
        // int j = r+l-i;
        p[i] = max( 0, min(r-i,p[r+l-i])); // p[j]
        // try extension of i until possible
        int k = p[i];
        while(i+k<n and i-k>=0 and t[i-k]==t[i+k]) k++;
        p[i] = k;
        if(i+k>r) r = i+k, l=i-k;
    }

    
    // for(int i=1;i<n;i++){ // replaced k with p[i]
    //     p[i] = max( 0, min(r-i,p[r+l-i])); // p[j]
    //     while(i+p[i]<n and i-p[i]>=0 and t[i-p[i]]==t[i+p[i]]) p[i]++;
    //     if(i+p[i]>r) r = i+p[i], l=i-p[i];
    // }
}

int32_t main()
{
    string s; cin>>s;
    manachers(s);
    return 0;
}
