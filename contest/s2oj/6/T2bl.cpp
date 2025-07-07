#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
const ll mod = 998244353;
int n,a[maxn],b[13];ll ans;
vector<int> v2,v3;
ll jc[maxn],jc_inv[maxn];
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b) {
        if (b&1ll) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1ll; 
    }
    return ret;
}
int pos6[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        jc[i] = jc[i-1]*i%mod;
        jc_inv[i] = binpow(jc[i],mod-2);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]%2==0) v2.push_back(a[i]);
        if (a[i]%3==0) v3.push_back(a[i]);
        if (flag&&a[i]!=1&&a[i]!=2&&a[i]!=3) flag = false;
    }
    int r[13],tmp[13];
    memset(tmp,0,sizeof(tmp));
    for (int i = 1; i <= n; i++) tmp[a[i]]++;
    for (int i = 1; i <= n; i++) r[i] = i;
    do{
        
        vector<int> c2,c3;
        for (int i = 1; i <= n; i++) {
            b[i] = a[r[i]];
            
            if (b[i]%2==0) c2.push_back(b[i]);
            if (b[i]%3==0) c3.push_back(b[i]);
        }
        if (c2 == v2 && c3 == v3) ++ans;
    }while (next_permutation(r+1,r+n+1));
    for (int i = 1; i <= 9; i++) ans = ans * jc_inv[tmp[i]] % mod;
    cout << ans << '\n';

    return 0;
}