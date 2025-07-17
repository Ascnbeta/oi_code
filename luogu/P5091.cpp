#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a,b,m;
inline ll eular(ll x) {
    ll ret = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ret /= i;
            ret *= (i-1);
            while (x%i==0) x/=i;
        }
    }
    if (x != 1) {
        ret /= x,ret *= (x-1);
    }
    return ret;
}
inline ll binpow(ll base,ll b,ll mod) {
    ll ret = 1;
    while (b) {
        if (b&1ll) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1ll;
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> a >> m;
    ll phi = eular(m);
    if (__gcd(a,m) == 1) {
        char ch;
        while (cin >> ch) {
            int num = ch-'0';
            b = (b*10%phi+num)%phi;
        }
        cout << binpow(a,b,m) << '\n';
    }else{
        char ch;
        bool f = true;
        while (cin >> ch) {
            int num = ch-'0';
            b = b * 10 + num;
            if (b > phi) b %= phi,f = false;
        }
        if (!f) b += phi;
        cout << binpow(a,b,m) << '\n';
    }
    return 0;
}