#include <bits/stdc++.h>
using namespace std;
int n;
double t[1<<21],p[1<<21],sum[1<<21];
double ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 0; i < (1<<n); i++) cin >> p[i],sum[i] = p[i];
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < (1<<n); i++) {
            if (i&(1<<j)) sum[i] += sum[i^(1<<j)];
        }
    }
    for (int i = 1; i < (1<<n); i++) {
        int len = __builtin_popcount(i);
        int tmp = -1;
        if (len&1) tmp = 1;
        double x = 1;
        x -= sum[((1<<n)-1)^i];
        if (x == 0) {
            puts("INF"); 
            return 0;
        }
        ans += 1.00*tmp/x;
    }
    printf("%.10f",ans);
    return 0;
}