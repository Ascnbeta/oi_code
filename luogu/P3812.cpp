#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 53;
ll p[maxn],n;
inline void insert(ll x) {
    for (int i = 49; i >= 0; i-- ){
        if (((x>>i)&1)^1) continue;
        if (!p[i]) return p[i] = x,void();
        x ^= p[i];
    }
}
inline ll querymax() {
    ll ret = 0;
    for (int i = 49; i >= 0; i--) {
        ret = max(ret,ret^p[i]);
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        insert(a);
    }
    cout << querymax() << '\n';
    return 0;
}