#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int n,m;
int a[maxn],ans;

int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    rt[0] = build(1,n);
    for (int i = 1; i <= n; i++) {
        rt[i] = insert(rt[i-1],a[i],1,n);
        if (a[i] == n) continue;
        ans += query(rt[i],a[i]+1,n,1,n);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << ans << '\n';
        int p = idx[x];
        int upper = query(rt[n],1,x-1,1,n) - query(rt[p],1,x-1,1,n);
        int lower = query(rt[p],x+1,n,1,n);
        ans -= lower + upper - query(p);
        modify(p,n,1);
    }
    return 0;
}