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

int n; 
vi tree,a;

int combine(int a,int b){
    return min(a,b);
}

void build(int l,int r,int index){
    if(l==r){ // leaf node -> base case
        tree[index] = a[l];
        return;
    }

    // recursive case
    int mid = (l+r)/2;
    build(l,mid,2*index); // left ch build
    build(mid+1,r,2*index+1); // right child build

    tree[index]  = combine(tree[2*index] , tree[2*index+1]); 
    // conbine both childs
}

void update(int l,int r,int index,int pos,int value){
    if(l==r){ // leaf node -> base case
        tree[index] = value;
        return;
    }

    // recursive case
    int mid = (l+r)/2;
    if(pos<=mid) update(l,mid,2*index,pos,value); // left ch update
    else update(mid+1,r,2*index+1,pos,value); // right child update

     tree[index]  = combine(tree[2*index] , tree[2*index+1]);
    // conbine both childs
}

int query(int l,int r,int index,int pos){
    if(l==r){ // leaf node -> base case
        return tree[index];
    }

    // recursive case
    int mid = (l+r)/2;
    if(pos<=mid) return query(l,mid,2*index,pos); // left ch query
    else return query(mid+1,r,2*index+1,pos); // right child query
}

int queryRange(int l,int r,int index,int ql,int qr){
    if(l==r){ // leaf node -> base case
        return tree[index];
    }

    // complete overlap
    if(ql<=l and r<=qr) return tree[index];

    // no overlap
    if(qr<l or ql>r) return 1e18; // default value

    // partial overlap
    int mid = (l+r)/2;
    int left = queryRange(l,mid,2*index,ql,qr); // left ch query
    int right = queryRange(mid+1,r,2*index+1,ql,qr); // right child query

    return  combine(left , right);
}

void solve(){
    cin>>n;
    tree.resize(4*n,0);

    vi a(n); for(auto &i:a) cin>>i;

    build(0,n-1,1);
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
