#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
const int maxm = 1e5+5;
struct edge{
    int u,v,w,chs;
    bool operator < (const edge &y) const{
        return w < y.w;
    }
    bool operator > (const edge &y) const{
        return w > y.w;
    }
}e[maxm];
int father[maxn];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
int n,m,k;
int cnt = 0;
bool f[maxm];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w,cnt += e[i].w^1;
    if (cnt < k) {
        cout <<"no solution" << '\n';
        return 0;
    }
    cnt = 0;
    sort(e+1,e+m+1);
    for (int i = m; i >= 1; i--) {
        int p = find(e[i].u),q = find(e[i].v);
        if (p != q) {
            e[i].chs = 1;
            cnt += (e[i].w==0);
            father[p] = q;
        }
    }
    if (cnt > k) {
        cout << "no solution" << '\n';
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        if (e[i].w == 0 && e[i].chs == 1) f[i] = true;
        e[i].chs = 0;
    }
    for (int i = 1; i <= n; i++) father[i] = i;
    cnt = 0;
    for (int i = 1; i <= m; i++) {
        int p = find(e[i].u),q = find(e[i].v);
        if (p != q) {
            e[i].chs = 1;
            father[p] = q;
            ++cnt;
        }
    }
    if (cnt < n-1) {
        cout << "no solution" << '\n';
        return 0;
    }
    for (int i = 1; i <= m; i++) if (e[i].w == 1 && e[i].chs == 1) f[i] = true;
    for (int i = 1; i <= n; i++) father[i] = i;
    cnt = 0;int cntk = 0;
    for (int i = 1; i <= m; i++) {
        int p = find(e[i].u),q = find(e[i].v);
        if (f[i]) ++cnt,father[p] = q;
        if (f[i]&&e[i].w == 0) ++cntk;
    }
    if (cnt > n-1) {
        cout << "no solution" << '\n';
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int p = find(e[i].u),q = find(e[i].v);
        if (cntk == k && e[i].w == 0) continue;
        if (p != q) {
            f[i] = true;
            ++cnt;
            if (e[i].w == 0) ++cntk;
            father[p] = q;
        }
        if (cnt == n-1) break;
    }
    if (cntk < k) {
        cout << "no solution" << '\n';
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        if (f[i]) {
            cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
        }
    }
    return 0;
}