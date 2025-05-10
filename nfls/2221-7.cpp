#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
int n,m,c[maxn];
const int maxn = 1e5+30;
const int mod = 1e9+7;
struct matrix{
    int l,r,a[3][3];
    matrix(int x,int y) {
        l = x,r = y;
        memset(a,0,sizeof(a));
    }
    void init(int x,int y) {
        l = x,r = y;
        memset(a,0,sizeof(a));
    }
    void reset() {
        for (int i = 1; i <= l; i++) a[i][i] = 1;
    }
    matrix operator + (const matrix &y) {
        matrix c(l,r);
        assert(l==y.l),assert(r==y.r);
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) c.a[i][j] = (a[i][j]+y.a[i][j])%mod;
        }
        return c;
    }
    matrix operator * (const matrix &y) {
        matrix c(l,r);
        assert(r==y.l);
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                for (int k = 1; k <= r; k++) {
                    c.a[i][j] = (c.a[i][j]+(a[i][k]*y.a[k][j])%mod)%mod;
                }
            }
        }
    }
}val[maxn<<2];
int tag[maxn<<2];
inline matrix binpow(matrix base,int b) {
    matrix ret(base.l,base.r);
    ret.reset();
    while (b) {
        if (b&1)
    }
} 
inline void build(int p,int l,int r) {
    if (l == r) {
        val[p].init(1,2);
        val[p].a[1][1] =  
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    build(1,1,n);
    return 0;
}