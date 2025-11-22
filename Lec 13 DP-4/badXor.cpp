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
    int n,m; cin>>n>>m;

    vvi a(n,vi(m)); for(auto &r:a) for(auto &i:r) cin>>i;

    bool isAnsFound = 0;
    for(int bit =0;bit<=10;bit++){

        vvi mat(n,vi(m,0));
        vi cnt1(n,0);

        int allOneRows = 0, isBothAvailable =0, remainXor = 0, rowNo;
        int mask = (1<<bit);

        loop(i,0,n){
            loop(j,0,m){
                // check set bit
                mat[i][j] = (a[i][j]&mask);
                if(mat[i][j]) cnt1[i]++;
            }

            if(cnt1[i]==m) // all ones
                allOneRows++;
            if(cnt1[i]!=m and cnt1[i]!=0){ // cnt1 != no ofCols and !=0
                rowNo = i;
                isBothAvailable=1;
            }
        }

        // find a row with both 0 and 1
        if(isBothAvailable){
            isAnsFound = 1;
            // ans hai
            cout<<"TAK"<<endl;
            // print based on n-1 rows
            loop(i,0,n) if(i!=rowNo) remainXor^=mat[i][0];

            if((remainXor) == 0){ // check if curr bit is 0 
                // is row m se 1 chaiye
                int colNo = -1;
                loop(j,0,m){
                    if(mat[rowNo][j]){
                        colNo = j;
                        break;
                    }
                }

                loop(i,0,n){
                    if(rowNo==i) cout<<colNo+1<<" ";
                    else cout<<1<<" "; 
                }
            }
            else{
                // yhn se 0 chaiye
                int colNo = -1;
                loop(j,0,m){
                    if(mat[rowNo][j]==0){
                        colNo = j;
                        break;
                    }
                }

                loop(i,0,n){
                    if(rowNo==i) cout<<colNo+1<<" ";
                    else cout<<1<<" "; 
                }
            }

        }
        else{
            if(allOneRows&1){
                isAnsFound = 1;
                // ans hai
                cout<<"TAK"<<endl;
                // print any value a[0]
                loop(i,0,n) cout<<1<<" ";
                cout<<endl;
            }
            else{
                // ans nahi hai
            }
        }
        // check no of rows with all 1s

        if(isAnsFound) break;
    }
    if(!isAnsFound)cout<<"NIE"<<endl;
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
