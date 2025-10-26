#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int n = a.size();

    vector<int> preSum(n+1,0); // 1-based
    // preSum[0]=0;
    // pre[n] -> sum of first n nos

    for(int i=1;i<=n;i++) preSum[i]= preSum[i-1] + a[i-1];

    // 2 4
    cout<<preSum[4] - preSum[2-1] << endl;
    
    // 1 6
    cout<<preSum[6] - preSum[1-1] << endl;
    

    return 0;
}