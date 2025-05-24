#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int c[12];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++) {
        int cnt;
        scanf("%d",&cnt);
        for (int j = 1; j <= cnt; j++) {
            int x;
            scanf("%d",&x);
            c[i] |= (1<<(x-1));
        }
    }
    for (int i = 1; i < (1<<m); i++) {
        int tmp = 0;
        for (int j = 1; j <= m; j++) {
            if (i&(1<<(j-1))) {
                tmp |= c[j];
            }
        }
        if (tmp == (1<<n)-1) ++ans;
    }
    printf("%d",ans);
    return 0;
}