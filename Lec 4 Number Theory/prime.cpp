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

bool isPrime(int n)
{ // tc -> O(n)
    if (n <= 1) return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool rootNPrime(int n) // tc -> O(root n)
{
    // for (int i = 2; i * i <= n; i++)
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void factors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i * i != n)
                cout << n / i << " ";
        }
    }
}

void sieveBasic(int n){ // O(n*loglogn)

    vi isPrime(n+1,1);
    isPrime[0] =0, isPrime[1] = 0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            // iske multiples ko not prime mark kardo
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=0;
            }
        }
    }

    for(int i=2;i<=n;i++) if(isPrime[i]) cout<<i<<" ";
    cout<<endl;
}

vi sieve(int n) // O(n*loglog rootn)
{
    vector<bool> isPrime(n + 1, 1); // initially all true
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= n; i++) // till root n
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i) // itertate on multiples
                isPrime[j] = 0; // you are not a prime
        }
    }
    vi res;
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) res.push_back(i);
    return res;
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
