#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+30;
const int mod = 1e9+7;
int n,m,ans = 1;
int f[maxn][25];
int find(int x,int k) {
    if (x == f[x][k]) return x;
    else return f[x][k] = find(f[x][k],k);
}
inline void init() {
    for (int i = __lg(n); i >= 0; i--) {
        for (int j = 1; j+(1<<i)-1 <= n; j++) {
            f[j][i] = j;
        }
    }
}
inline void merge(int x,int y,int k) {
    int p = find(x,k),q = find(y,k);
    f[p][k] = q;
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int len = __lg(r1-l1+1);
        merge(l1,l2,len);
        merge(r1-(1<<len)+1,r2-(1<<len)+1,len);
    }
    for (int i = __lg(n); i >= 1; i--) {
        for (int j = 1; j+(1<<i)-1 <= n; j++) {
            if (find(j,i) != j) {
                int t = f[j][i];
                merge(j,t,i-1);
                merge(j+(1<<(i-1)),t+(1<<(i-1)),i-1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (f[i][0] == i) {
            ans = ans * (ans==1?9:10) % mod;
        }
    }
    cout << (ans==1?0:ans) << '\n';
    return 0;
}