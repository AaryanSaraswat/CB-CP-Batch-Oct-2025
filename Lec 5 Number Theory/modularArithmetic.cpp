#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 1) return a;

    int haflPower = power(a, b / 2);
    int ans = haflPower * haflPower;
    if (b & 1)
        ans *= a;
    return ans;
}

int power(int a, int b, int m)
{
    if (b == 0)
        return 1;
    if (a > m)
        a %= m;
    int halfPow = power(a, b / 2, m) % m;
    int result = (halfPow % m * halfPow % m) % m;
    if (b & 1)
        result = result * a % m;
    return result;
}

int main()
{
    // cout<<((4%4-9%4)+4)%4<<endl;

    int A = 4, B = 10;
    int mod = 1e9 + 7;

    // cout<<(A+b)%mod
    cout << (A % mod + B % mod) % mod << endl;
    
    // cout<<(A-b)%mod
    cout << (A % mod - B % mod + mod) % mod << endl;
    
    // cout<<(A*b)%mod
    cout << (A % mod * B % mod) % mod << endl;

    // cout << (a/b) % mod;

    // int modInvB = powerr(b,mod-2,mod)
    int modInvB = power(B,mod-2,mod);
    cout << (A % mod * modInvB % mod) % mod << endl;

    return 0;
}