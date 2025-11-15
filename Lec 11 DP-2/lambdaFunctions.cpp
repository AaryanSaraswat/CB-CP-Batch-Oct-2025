#include <bits/stdc++.h>
using namespace std;

int sum(int i,int j,vector<int> pre){
    pre[0]=10;
    return pre[j] - ((i-1>=0) ? pre[i-1]:0);
}

int main()
{
    vector<int> pre(10,0); // 0-based
    //////
    auto sum=[&](int i,int j){
        return pre[j] - ((i-1>=0) ? pre[i-1]:0);
    };

    // function<int(int)> sum=[&](int i){};

    return 0;
}