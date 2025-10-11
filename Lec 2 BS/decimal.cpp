#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

bool f(lli mid,int x){
    return mid*mid<=x;
}

class Solution {
public:
    int mySqrt(int x) {
        double st = 0, en = x, ans= 0.0;

        double precision = (1e-7);

        while(en-st>precision){
            double mid  = (st)+(en-st)/2;
            if(f(mid,x)) ans = mid , st = mid + precision;
            else en = mid - precision;
        }
        return ans;
    }
};