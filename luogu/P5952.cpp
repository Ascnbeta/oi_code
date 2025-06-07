#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
const int maxn = 5e5+30;
int n,m;
ll H;
struct edge{
    int x,y;
    int h;
    bool operator < (const edge &y) const {
        return h < y.h;
    }
};
vector<edge> e;
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
inline void read(ll &x) {
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
int father[maxn],rk[maxn],h[maxn];
ll ans[maxn];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y,int v) {
    int p = find(x),q = find(y);
    if (p == q) return;
    if (rk[p] < rk[q]) {
        father[p] = q;
        rk[q] = max(rk[p]+1,rk[q]);
        ans[q] = 1ll*(1ll*ans[p]+v-h[p]+mod)%mod*(1ll*ans[q]+v-h[q]+mod)%mod;
        h[p] = h[q] = v;
    }else{
        father[q] = p;
        rk[p] = max(rk[q]+1,rk[p]);
        ans[p] = 1ll*(1ll*ans[p]+v-h[p]+mod)%mod*(1ll*ans[q]+v-h[q]+mod)%mod;
        h[p] = h[q] = v;
    }
    
}
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    read(n),read(m),read(H);
    for (int i = 1; i <= n*m; i++) father[i]=i,h[i]=0,ans[i]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int x;read(x);
            e.push_back({j+m*(i-1),(j+1)+m*(i-1),x});
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;read(x);
            e.push_back({(i-1)*m+j,i*m+j,x});
        }
    }
    sort(e.begin(),e.end());
    for (auto tmp : e) merge(tmp.x,tmp.y,tmp.h);
    printf("%lld",(ans[find(1)]+H-h[find(1)])%mod);
    return 0;
}