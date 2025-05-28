#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 113;
const int maxm = 2e4+30;
int s,n,m;
int a[maxn][maxn];
ll f[maxm],ans;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch < '0'||ch > '9') {
        if (ch == '-') f=-1;
        ch=getchar();
    }
    while (ch >= '0'&& ch <= '9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x=x*f;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(s),read(n),read(m);
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
            read(a[j][i]);
        }
    }
    for (int i = 1; i <= n; i++) sort(a[i]+1,a[i]+s+1);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= s; k++) {
                if (j>a[i][k]*2) f[j]=max(f[j],f[j-a[i][k]*2-1]+k*i);
            }
        }
    }
    for (int i = 0; i <= m; i++) ans=max(ans,f[i]);
    printf("%lld",ans);
    return 0;
}