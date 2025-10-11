#include <bits/stdc++.h>
using namespace std;

bool f(int x){
    // return true if condition is satisfied

    // return false if not
}

int main()
{
    int st = 0, en = 10, ans=-1;

    while(st<=en){
        int mid = (st+en)/2; // st+(en-st)/2;
        if(f(mid)) ans = mid, en=mid-1;
        else st = mid+1;
    }

    cout<<ans<<endl;
    
    return 0;
}