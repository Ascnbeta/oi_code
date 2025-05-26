#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,cnt;
double x1;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> x >> y;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i+j >= x || abs(i-j) >= y) ++cnt;
        }
    }
    x1 = (double)1.0*cnt/36;
    printf("%.10f",x1);
    return 0;
}