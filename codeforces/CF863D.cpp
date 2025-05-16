#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,q,m;
int val[maxn];
int t[maxn],l[maxn],r[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= q; i++) {
        cin >> t[i] >> l[i] >> r[i];
    }
    while (m--) {
        int op;
        cin >> op;
        for (int i = q; i >= 1; i--) {
            if (op < l[i] || op > r[i]) continue;
            if (t[i] == 1) {
                if (op == l[i]) op = r[i];
                else op--;
            }else{
                op = r[i]-(op-l[i]);
            }
        }
        cout << val[op] << ' ';
    }
    return 0;
}