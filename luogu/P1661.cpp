#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x,y;
}a[54];
int n,ans;
int e[54][54];
bool f[54];
int dis[54];
inline void prim() {
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i < n; i++) {
        int p = 0;
        for (int j = 1; j <= n; j++) {
            if (!f[j]&&(p==0||dis[j]<dis[p])) p = j;
        }
        f[p] = true;
        for (int j = 1; j <= n; j++) {
            if (!f[j]) dis[j] = min(dis[j],e[p][j]);
        }
    }
}
signed main () {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            e[i][j] = e[j][i] = (abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+1) / 2;
        }
    }
    prim();
    for (int i = 1; i <= n; i++) {
        ans = max(ans,dis[i]);
    }
    cout << ans << '\n';
    return 0;
}