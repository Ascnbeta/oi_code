#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int mod = 1e9+7;
int T;
int n,m,v,v2,ans = 1;
vector<pair<int,int>> a;
vector<int> pos;
inline int binpow(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret % mod;
}
inline int solve(int now,int tgt) {
    assert(now >= tgt);
    int cnt = tgt - now - 1;
    if (cnt == 0) {
        return (1+v*(v-1)%mod)%mod;
    }else{
        return (v*(v-1)%mod*binpow(v2,cnt)%mod+v*solve(now+1,tgt)%mod)%mod; 
    }
}
signed main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        a.clear();
        pos.clear();
        ans = 1;
        cin >> n >> m >> v;
        v2 = binpow(v,2);
       
        for (int i = 1; i <= m; i++) {
            int x,y;
            cin >> x >> y;
            a.push_back({x,y});
        }
        sort(a.begin(),a.end());
        int m1 = unique(a.begin(),a.end())-a.begin();
        bool f = false;
        for (int i = 0; i < m1; i++) {
            if (i > 0) {
                if (a[i-1].fi == a[i].fi && a[i-1].se != a[i].se) {
                    cout << 0 << '\n';
                    f = true;
                    break;
                }
            }
            pos.push_back(a[i].fi);
        }
        if (f) continue;
        for (int i = 0; i < pos.size(); i++) {
            if (i == 0) ans = ans * binpow(v2,pos[i]-1) % mod;
            if (i+1 == pos.size()) {
                ans = ans * binpow(v2,n-pos[i]) % mod;
                break;
            }
            if (i+1 < pos.size()) ans = ans * (binpow(v2,pos[i+1]-pos[i]) - binpow(v,pos[i+1]-pos[i]-1) * (v - 1) % mod) % mod;
            // cout << ans << ' ';
        }
        // cout << '\n';
        if (ans < 0) ans += mod;
        cout << ans << '\n';
    }
    return 0;
}   