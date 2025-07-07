#include <bits/stdc++.h>
#define pll pair<ll,ll>
typedef long long ll;
using namespace std;
const int maxn = 2e6+5;
const ll p1 = 59;const ll p2 = 31;
const ll mod1 = 998244353;const ll mod2 = 1e9+7;
int n;
ll pow1[maxn],pow2[maxn];
inline pll h(string t) {
    pll ret = {0,0};
    for (int i = 0; i < t.size(); i++) {
        ret.first += (t[i]-'a')*pow1[t.size()-i-1]%mod1;
        ret.first %= mod1;
        ret.second += (t[i]-'a')*pow2[t.size()-i-1]%mod2;
        ret.second %= mod2;
    }
    return ret;
}
map<pll,int> mp;
inline ll binpow(ll base,ll b,int chs) {
    ll ret = 1;
    if (chs == 1) {
        while (b) {
            if (b&1ll) ret = ret * base % mod1;
            base = base * base % mod1;
            b >>= 1ll;
        }
    }else{
        while (b) {
            if (b&1ll) ret = ret * base % mod2;
            base = base * base % mod2;
            b >>= 1ll;
        }
    }
    return ret;
}
ll ans = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= 2e6+1; i++) {
        pow1[i] = pow1[i-1] * p1 % mod1;
        pow2[i] = pow2[i-1] * p2 % mod2;
    }
    for (int i = 1; i <= n; i++) {
        int k;string s;
        cin >> k >> s;
        pll val = h(s);
        ll a = binpow(p1,k,1),b = binpow(p2,k,2);
        a = binpow(a-1,mod1-2,1),b = binpow(b-1,mod2-2,2);
        pll tmp = {val.first*a%mod1,val.second*b%mod2};
        ans += mp[tmp];
        mp[tmp]++;
    }
    cout << ans*2+n << '\n';
    return 0;
}