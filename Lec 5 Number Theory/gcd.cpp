#include <bits/stdc++.h>
using namespace std;

int customGcd(int a,int b){
    if(a==0) return b;
    return customGcd(b%a,a);
}

int main()
{
    // cout<<customGcd(10,0)<<endl; // 1  10 

    cout<<__gcd(10,0)<<endl;
    cout<<gcd(10,0)<<endl;
    return 0;
}