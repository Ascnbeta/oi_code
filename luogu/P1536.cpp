#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int father[1004],rk[1004];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return;
    if (rk[p] <= rk[q]) {
        father[p] = q;
        rk[q] = max(rk[q],rk[p]+1);
    }else{
        father[q] = p;
        rk[p] = max(rk[p],rk[q]+1);
    }
}
int main () {
    while(1) {
        cin >> n >> m;
        if (n == 0) return 0;
        ans = 0;
        for (int i = 1; i <= n; i++) father[i] = i;
        for (int i = 1; i <= m; i++) {
            int u,v;
            cin >> u >> v;
            merge(u,v);
        }
        for (int i = 1; i <= n; i++) {
            if (father[i] == i) ++ans;
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}