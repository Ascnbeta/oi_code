#include <bits/stdc++.h>
using namespace std;
int n,m;
struct relation{
    int a,b,v;
    bool operator < (const relation &y) const{
        return v > y.v;
    }
}r[100005];
int father[100004],rk[100004];
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
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) cin >> r[i].a >> r[i].b >> r[i].v;
    sort(r+1,r+m+1);
    for (int i = 1; i <= m; i++) {
        if (find(r[i].a)==find(r[i].b)) {
            cout << r[i].v << '\n';
            return 0;
        }
        merge(r[i].a,r[i].b+n);
        merge(r[i].a+n,r[i].b);
    }
    cout << 0 << '\n';
    return 0;
}