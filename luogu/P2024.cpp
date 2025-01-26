#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
int father[150004],rk[150004];
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
inline void merge(int p,int q) {
    int x = find(p);
    int y = find(q);
    if (x == y) return;
    if (rk[x] <= rk[y]) {
        father[x] = y;
        rk[y] = max(rk[y],rk[x]+1);
    }else{
        father[y] = x;
        rk[x] = max(rk[x],rk[y]+1);
    }
}
int main () {
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++) father[i] = i;
    for (int i = 1; i <= k; i++) {
        int op,x,y;
        cin >> op >> x >> y;
        if (x > n || y > n) {
            ++ans;
            continue;
        }
        if (op == 1) {
            if (find(x+n)==find(y)||find(x+2*n)==find(y)) {
                ++ans;
                continue;
            }
            merge(x,y);
            merge(x+n,y+n);
            merge(x+2*n,y+2*n);
        }else{
            if (x == y || find(x)==find(y) || find(x+n)==find(y)) {
                ++ans;
                continue;
            }
            merge(x,y+n);
            merge(x+2*n,y);
            merge(x+n,y+2*n);
        }
    }
    cout << ans << '\n';
    return 0;
}