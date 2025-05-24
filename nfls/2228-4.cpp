#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
ll f[100][2];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%lld",&n);
    ll k = __lg(n);
    if (n&1ll) {
        f[1][1] = 0,f[1][0] = 1;
    }else{
        f[1][1] = 1,f[1][0] = 1;
    }
    for (int i = 1; i < k; i++) {
        if (n&(1ll<<i)) {
            f[i+1][1] = f[i][1];
            f[i+1][0] = f[i][1]+f[i][0];
        }
        if ((n&(1ll<<i))==0) {
            f[i+1][1] = f[i][0]+f[i][1];
            f[i+1][0] = f[i][0];
        }
    }
    if (k==0) puts("1");
    else printf("%lld",f[k][1]+f[k][0]);
    return 0;
}