#include <bits/stdc++.h>
using namespace std;
int n,ans;
int e[103][103];
bool f[103];
int dis[103];
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
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> e[i][j];
        }
    }
    prim();
    for (int i = 1; i <= n; i++) ans += dis[i];
    cout << ans << '\n';
    return 0;
}