#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+30;
int n,v;
struct goal{
    int t,a;
    bool operator < (const goal &y) const{
        return t < y.t;
    }
}g[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> v;
    for (int i = 1; i <= n; i++) cin >> g[i].t;
    for (int i = 1; i <= n; i++) cin >> g[i].a;
    sort(g+1,g+n+1);
    
    return 0;
}