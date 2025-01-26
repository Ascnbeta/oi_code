#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
int c[504][504];
int father[300019];
int dx[5] = {0,0,0,-1,1},dy[5] = {0,-1,1,0,0};
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    while (t != father[t]) {
        int w = father[t];
        father[t] = x;
        t = w;
    }
    return x;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n*n; i++) {
        father[i] = i;
    }
    while (m--) {
        int p,x,y;
        cin >> p >> x >> y;
        ++p;
        c[x][y] = p;
        ++cnt;
        for (int i = 1; i <= 4; i++) {
            int tx = x + dx[i],ty = y + dy[i];
            if (c[tx][ty] != p) continue;
            int t1 = find((x-1)*n+y),t2 = find((tx-1)*n+ty);
            if (t1 != t2) father[t2] = t1,--cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}