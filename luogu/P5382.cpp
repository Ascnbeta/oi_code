#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template <typename T>
inline void read(T &x) {
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
const int maxn = 5e5+10;
int n,k;
ll a[maxn],sum[maxn],ans;
ll trie[maxn*35][2],tot,siz[maxn*70];
inline void insert(ll x) {
    ll p = 0;
    for (ll i = 31; i >= 0; i--) {
        ll tp = (x>>i)&1ll;siz[p]++;
        if (!trie[p][tp]) trie[p][tp] = ++tot;
        p = trie[p][tp];
    }
    siz[p]++;
}
inline ll query(ll x,ll rk) {
    ll p = 0;ll ret = 0;
    for (ll i = 31; i >= 0; i--) {
        ll tp = (x>>i)&1ll;
        if (!trie[p][tp^1ll]) p = trie[p][tp];
        else if (rk<=siz[trie[p][tp^1ll]]) p = trie[p][tp^1],ret |= 1ll<<i;
        else rk -= siz[trie[p][tp^1]],p = trie[p][tp];
    }
    return ret;
}
struct node{
    int pos;ll w;int rk;
    bool operator < (const node &y) const{
        return w < y.w;
    }
};
priority_queue<node> q;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(k);k*=2;
    insert(sum[0]);
    for (int i = 1; i <= n; i++) read(a[i]),sum[i]=a[i]^sum[i-1],insert(sum[i]);
    for (int i = 0; i <= n; i++) q.push({i,query(sum[i],1),1});
    while (k--) {
        node tmp = q.top();
        q.pop();
        ans += tmp.w;
        if (tmp.rk < n-1) q.push({tmp.pos,query(sum[tmp.pos],tmp.rk+1),tmp.rk+1});
    }
    printf("%lld",ans/2);
    return 0;
}