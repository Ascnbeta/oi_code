#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
const int maxm = 4e4+5;
int n,m;
struct mine{
    int x,y,w,v;
    double dis;
    bool operator < (const mine &y) const{
        return dis < y.dis;
    }
}a[maxn];
int f[maxm];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].w >> a[i].v;
        a[i].dis = sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
    }
    // sort(a+1,a+n+1);
    memset(f,0xc0,sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= a[i].w*2; j--) {
            f[j] = max(f[j],f[j-a[i].w*2]+a[i].v);
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) ans = max(ans,f[i]);
    cout << ans << '\n';
    return 0;
}