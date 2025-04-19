#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
const int T = 100001;
const int F = -100001;
const int U = 0; 
int c,t,n,m,ans;
int fa[maxn];
bool f[maxn<<1];
inline int find(int x) {
    if (x == T || x == F) return x;
    else if (f[n-x] || x == U) return U;
    else if (f[n+x]) return T;
    else if (x < 0) {
        if (x == -fa[-x]) return x;
        else{
             f[n+x] = 1;
             int tmp = find(-fa[-x]);
             f[n+x] = 0;
             return tmp;
        }
    }else{
        if(x == fa[x]) return x;
		else {
			f[n+x] = 1;
			int tmp = fa[x] = find(fa[x]);
			f[n+x] = 0;
            return tmp;
		}
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; i++) fa[i] = i;
        while (m--) {
            char op;
            cin >> op;
            if (op == '-') {
                int x,y;
                cin >> x >> y;
                fa[x] = -fa[y];
            }else if (op == '+') {
                int x,y;
                cin >> x >> y;
                fa[x] = fa[y];
            }else{
                int x;
                cin >> x;
                if (op == 'T') fa[x] = T;
                else if (op == 'F') fa[x] = F;
                else fa[x] = U;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (find(i) == U) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}