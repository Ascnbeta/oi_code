#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p1 = 31;
const int p2 = 131;
const int mod1 = 20220713;
const int mod2 = 1e9+7;
int n,ans;
map<pair<int,int>,int> mp;
inline int binpow1(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod1;
        base = base * base % mod1;
        b >>= 1;
    }
    return ret % mod1;
}
inline int binpow2(int base,int b) {
    int ret = 1;
    while (b) {
        if (b&1) ret = ret * base % mod2;
        base = base * base % mod2;
        b >>= 1;
    }
    return ret % mod2;
}
inline pair<int,int> Hash(string s) {
    int len = s.size();
    s = ' ' + s;
    int x = 0,y = 0;
    for (int i = 1; i <= len; i++) {
        x = (x+(s[i]*binpow1(p1,len-i)%mod1)%mod1);
        y = (y+(s[i]*binpow2(p2,len-i)%mod2)%mod2);
    }
    return make_pair(x,y);
}
signed main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        pair<int,int> x = Hash(s);
        if (mp.find(x) == mp.end()) ++ans,mp[x] = 1;
    }
    cout << ans << '\n';
    return 0;
}