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

vector<vector<int>> adj;
vi flatTree;
map<int,pair<int,int>> occurence; // node -> {firstOcc, secondOcc}

void dfs(int node,int parent){
    // entry of node
    flatTree.push_back(node);
    occurence[node].first = sz(flatTree)-1;

    for(auto ch:adj[node]){
        if(ch==parent) continue;
        dfs(ch,node);
    }

    // exit of node
    flatTree.push_back(node);
    occurence[node].second = sz(flatTree)-1;
}

vi segTree;

// build
void build(int l,int r,int idx,vi &a){
    if(l==r){
        segTree[idx] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(l,mid,2*idx,a);
    build(mid+1,r,2*idx+1,a);
    segTree[idx] = segTree[idx*2] + segTree[idx*2+1];
}

//update
void update(int l,int r,int idx,vi &a,int pos,int value){
    if(l==r){
        segTree[idx] = value;
        return;
    }

    int mid = (l+r)/2;
    if(pos<=mid) update(l,mid,2*idx,a,pos,value);
    else update(mid+1,r,2*idx+1,a,pos,value);
    segTree[idx] = segTree[idx*2] + segTree[idx*2+1];
}

//query
int query(int l,int r,int idx,int ql,int qr){
    // complete overlap
    if(ql<=l and r<=qr) return segTree[idx];
    
    // no overlap
    if(r<ql or l>qr) return 0; 

    // partial overlap
    int mid = (l+r)/2;
    int left = query(l,mid,2*idx,ql,qr);
    int right = query(mid+1,r,2*idx+1,ql,qr);
    return left+right;

}

void solve(){
    int n,q; cin>>n>>q;
    adj.resize(n+1);

    vi values(n+1);

    for(int i=1;i<=n;i++) cin>>values[i];

    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    // flat tree  + occurences
    vi a(flatTree.size(),0);
    for(auto [node,occ]:occurence){
        a[occ.first] = values[node];
    }

    segTree.resize(4*flatTree.size(),0); // 4*2*n
    build(0,flatTree.size()-1,1,a);

    while (q--)
    {
        int type; cin>>type;
        if(type==1){
            int node, value; cin>>node>>value;
            int pos = occurence[node].first;
            update(0,flatTree.size()-1,1,a,pos,value);
        }
        else{
            int node; cin>>node;
            cout<<query(0,flatTree.size()-1,1,occurence[node].first,occurence[node].second) << endl;
        }
    }
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
