#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int maxn = 504;
const int maxm = 503;
const int p1 = 31;
const int p2 = 137;
const int mod1 = 20220713;
const int mod2 = 1e9+7;
int n,m;
string a[maxn],b[maxn];
pair<int,int> ha[maxn][maxm],hb[maxn][maxm];
int vis[2][maxm];
inline int binpow(int base,int b,const int mod) {
    int bs = base,tb = b;
    if (base == 31) {
        if (vis[0][b]) return vis[0][b];
    }else{
        if (vis[1][b]) return vis[1][b];
    }
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    if (bs == 31) vis[0][tb] = ret % mod;
    else vis[1][tb] = ret % mod;
    return ret % mod;
}
inline pair<int,int> convert(string s) {
    s = ' ' + s;
    int len = s.size()-1;
    int x = 0,y = 0;
    for (int i = 1; i <= len; i++) {
        x = (x+s[i]*binpow(p1,len-i,mod1)%mod1)%mod1;
        y = (y+s[i]*binpow(p2,len-i,mod2)%mod2)%mod2;
    }
    return make_pair(x,y);
}
map<pair<int,int>,int> mp;
inline bool check(int x) {
    for (int l = 1; l+x-1 <= m; l++) {
        int r = l + x - 1;
        mp.clear();
        bool f = true;
        for (int i = 1; i <= n; i++) {
            pair<int,int> tmp = {(ha[i][r].fi-ha[i][l-1].fi*binpow(p1,r-l+1,mod1)%mod1+mod1)%mod1,(ha[i][r].se-ha[i][l-1].se*binpow(p2,r-l+1,mod2)%mod2+mod2)%mod2};
            if (mp.find(tmp) == mp.end()) mp[tmp] = 1;
        }
        for (int i = 1; i <= n; i++) {
            pair<int,int> tmp = {(hb[i][r].fi-hb[i][l-1].fi*binpow(p1,r-l+1,mod1)%mod1+mod1)%mod1,(hb[i][r].se-hb[i][l-1].se*binpow(p2,r-l+1,mod2)%mod2+mod2)%mod2};
            if (mp.find(tmp) != mp.end()) {
                f = false;
                break;
            }
        }
        if (f) return true;
    }
    return false;
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = ' ' + a[i];
        for (int j = 1; j <= m; j++) {
            ha[i][j] = convert(a[i].substr(1,j));
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = ' ' + b[i];
        for (int j = 1; j <= m; j++) {
            hb[i][j] = convert(b[i].substr(1,j));
        }
    }
    int l = 1,r = m,ans = m;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}