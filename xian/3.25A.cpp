#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,ans;
int a[maxn],b[maxn];
struct op{
    int l,r;
    bool operator < (const op y) const{
        if (l == y.l) return r < y.r;
        return l < y.l;
    }
};
vector<op> opt;
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        int x = b[i],y = b[a[i]];
        opt.push_back({min(x,y),max(x,y)});
        swap(b[a[x]],b[a[y]]);
        swap(a[i],a[x]);
        
        ++ans;
        
    }
    cout << ans << '\n';
    for (auto v : opt) cout << v.l << ' ' << v.r << '\n';
    return 0;
}