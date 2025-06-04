#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
int n,a;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
ll p[20003],tot;
int minp[200010];
inline void eular_sieve() {
	for (int i = 2; i <= 200000; i++) {
		if (!minp[i]) {
			p[++tot] = i;
			minp[i] = tot;
		}
		for (int j = 1; j<=minp[i]&&p[j]*i<=200000; j++) minp[p[j]*i] = j;
	}
}
int z[20003],maxx;
inline void solve(ll x) {
	if (x == 1) return;
	for (int i = 1; i <= tot && p[i]*p[i] <= x; i++) {
		if (x % p[i] == 0) {
            maxx = max(maxx,i);
			int cnt = 0;
			while (x%p[i]==0) ++cnt,x/=p[i];
			z[i] += cnt;
		}
	}
	if (x != 1) maxx=max(maxx,minp[x]),z[minp[x]]++;
}
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b){
        if (b&1ll) ret *= base;
        base *= base;
        b >>= 1ll;
    }
    return ret;
} 
inline bool check(ll x,int idx) {
    ll val = p[idx];
    ll cnt = 0;
    for (ll i = 1; binpow(val,i) <= x; i++) {
        cnt += x/binpow(val,i);
    }
    return cnt >= z[idx];
}
ll v = 1;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    eular_sieve();
    read(n);
    for (int i = 1; i <= n; i++) read(a),solve(a);
    for (int i = 1; i <= maxx; i++) {
        ll l = 1,r = 93256099981,ans = 93256099981;
        while (l <= r) {
            ll mid = (l+r)>>1;
            if (check(mid,i)) {
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        v = max((long long)ans,v);
    }
    printf("%lld",v);
    // for (int i = 1; i <= tot; i++) printf("\n%lld",p[i]);
    // int cur = 0;
    // for (int i = 1; i <= tot; i++) {
    //     ll val = p[i];
    //     ll cnt = 0,tmp;
    //     for (ll j = 1; binpow(val,j) <= 100000; j++) tmp++;
    //     for (ll j = 1; binpow(val,j) <= (tmp+1)*100000; j++) {
    //         cnt += (tmp+1)*100000/binpow(val,j);
    //     }
    //     if (cnt > v) cur = i,v = cnt;
    // }
    // printf("%lld %d",v,cur);
    return 0;
}