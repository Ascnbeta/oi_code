#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e4+5;
int n,L;
int C[maxn];
ll c[maxn],d[maxn],sum[maxn],k[maxn],b[maxn];
ll f[maxn];
int q[maxn<<1],l,r;
inline ll calc(int j,int i) {
    return f[j]+d[j]*d[j]+k[j]*c[i];
}
inline bool check(int p1,int p2,int p3) {
    return (b[p1]-b[p3])*(k[p3]-k[p2])>=(b[p2]-b[p3])*(k[p3]-k[p1]);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> L;
    for (int i = 1; i <= n; i++) cin >> C[i],sum[i] = sum[i-1] + C[i];
    for (int i = 1; i <= n; i++) c[i] = sum[i]+i-L-1,d[i] = sum[i]+i,k[i] = -2*d[i];
    l = r = 1;
    for (int i = 1; i <= n; i++) {
        while (l<r&&calc(q[l],i)>=calc(q[l+1],i)) ++l;
        f[i] = calc(q[l],i)+c[i]*c[i];
        b[i] = f[i]+d[i]*d[i];
        while (l<r&&check(q[r-1],q[r],i)) --r;
        q[++r] = i;
    }
    cout << f[n] << '\n';
    return 0;
}