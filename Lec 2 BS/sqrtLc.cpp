#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

bool f(lli mid,int x){
    return mid*mid<=x;
}

class Solution {
public:
    int mySqrt(int x) {
        int st = 0, en = x/2+1, ans= 0;
        while(st<=en){
            int mid  = (st)+(en-st)/2;
            if(f(mid,x)) ans = mid , st = mid +1;
            else en = mid - 1;
        }
        return ans;
    }
};