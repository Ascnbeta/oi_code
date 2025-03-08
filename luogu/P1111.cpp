#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct road{
    int u,v,t;
    bool operator < (const road &y) const{
        return t < y.t;
    }
}r[100005];
int father[1003],rk[1003];
inline int find(int x) {
    int t = x;
    while(x != father[x]) x = father[x];
    int w;
    while(t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return;
    --cnt;
    if (rk[p] <= rk[q]) {
        father[p] = q;
        rk[q] = max(rk[q],rk[p]+1);
    }else{
        father[q] = p;
        rk[p] = max(rk[p],rk[q]+1);
    }
}
int main () {
    cin >> n >> m;
    cnt = n;
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) cin >> r[i].u >> r[i].v >> r[i].t;
    sort(r+1,r+m+1);
    for (int i = 1; i <= m; i++) {
        merge(r[i].u,r[i].v);
        if (cnt == 1) {
            cout << r[i].t << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}