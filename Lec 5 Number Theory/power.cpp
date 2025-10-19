#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){
    if(b==1) return a;
    int haflPower = power(a,b/2);
    int ans = haflPower * haflPower;
    if(b&1) ans*=a;
    return ans;
}

int power(int a, int b, int m)
{
    if (b == 0) return 1;
    if(a>m) a %= m;
    int halfPow = power(a, b / 2, m) % m;
    int result =(halfPow% m * halfPow % m) % m;
    if (b & 1)  result = result * a % m;
    return result;
}

int main()
{
    
    return 0;
}