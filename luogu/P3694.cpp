#include <bits/stdc++.h>
using namespace std;
int n,m;
int sum[24][100003];
int num[24];
int tot[1500000],f[1500000];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int j = 1; j <= m; j++) {
            if (j != x) sum[j][i]=sum[j][i-1];
            else sum[j][i]=sum[j][i-1]+1;
        }
        ++num[x];
    }
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for (int i = 1; i < (1<<m); i++) {
        int cnt = 1,t = i,tmp = 0;
        while (t) {
            if (t&1) tmp += num[cnt];
            ++cnt;
            t >>= 1;
        }   
        tot[i] = tmp;
    }
    for (int i = 1; i < (1<<m); i++) {
        for (int j = 1; j <= m; j++) {
            if ((i>>(j-1))&1) {
                int t = i ^ (1<<(j-1));
                int l = tot[t],r = tot[i];
                f[i]=min(f[i],f[t]+num[j]-(sum[j][r]-sum[j][l]));
            }
        }
    }
    cout << f[(1<<m)-1] << '\n';
    return 0;
}