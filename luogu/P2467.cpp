#include <bits/stdc++.h>
using namespace std;
const int maxn = 4203;
int n,p,ans;
int f[maxn][2];
int sum[maxn][2];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%d%d",&n,&p);
    sum[1][0]=1,sum[1][1]=1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[j][1] = sum[j-1][0];
            f[j][0] = (sum[i-1][1]-sum[j-1][1]+p)%p;
        }

        for (int j = 1; j <= i; j++) sum[j][1] = (sum[j-1][1]+f[j][1])%p,sum[j][0] = (sum[j-1][0]+f[j][0])%p;
    }
    for (int i = 1; i <= n; i++) ans = ((ans+f[i][0])%p+f[i][1])%p;
    printf("%d",ans);
    return 0;
}