#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int father[2004],rk[2004];
bool f[2004];
inline int find(int x){
    int t = x;
    while (father[x] != x) {
        x = father[x];
    }
    while (t != father[t]) {
        int w = father[t];
        father[t] = x;
        t = w;
    }
    return x;
}
inline void merge(int x,int y) {
    int p = find(x);
    int q = find(y);
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
    for (int i = 1; i <= 2*n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) {
        char opt;int p,q;
        cin >> opt >> p >> q;
        if (opt == 'F') {
            merge(p,q);
        }else{
            merge(p+n,q);
            merge(q+n,p);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!f[find(i)]) {
            ++ans;
            f[father[i]] = true;
        }
    }
    cout << ans << '\n';
    return 0;
}