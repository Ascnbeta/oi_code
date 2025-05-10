#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
#define int long long
const int maxn = 1e5+30;
int n,m,c[maxn];
const int mod = 1e9+7;
struct matrix{
    int l,r,a[3][3];
    void init(int x,int y) {
        l = x,r = y;
        a[1][1] = a[1][2] = a[2][1] = a[2][2] = 0;
    }
    void reset() {
        a[1][1] = a[2][2] = 1;
    }
    matrix operator + (const matrix &y) {
        matrix c;c.init(l,r);
        c.a[1][1] = (a[1][1] + y.a[1][1]) % mod;
        c.a[1][2] = (a[1][2] + y.a[1][2]) % mod;
        c.a[2][1] = (a[2][1] + y.a[2][1]) % mod;
        c.a[2][2] = (a[2][2] + y.a[2][2]) % mod;
        return c;
    }
    matrix operator * (const matrix &y) {
        matrix c;c.init(l,r);
        assert(r==y.l);
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                for (int k = 1; k <= r; k++) {
                    c.a[i][j] = (c.a[i][j]+(a[i][k]*y.a[k][j])%mod)%mod;
                }
            }
        }
        return c;
    }
    bool operator != (const matrix &y) const{
        return (a[1][1] != y.a[1][1] || a[1][2] != y.a[1][2] || a[2][1] != y.a[2][1] || a[2][2] != y.a[2][2]);
    }
};
matrix val[maxn<<2],tag[maxn<<2];
// vector<matrix> val(maxn<<2);
inline matrix binpow(matrix base,int b) {
    matrix ret;ret.init(base.l,base.r);
    ret.reset();
    while (b) {
        if (b&1) ret = ret * base;
        base = base * base;
        b >>= 1;
    }
    return ret;
} 
matrix fst,tr,qwq;
inline void pushup(int p) {
    val[p] = val[ls] + val[rs];
}
inline void pushdown(int p) {
    val[ls] = val[ls] * tag[p];
    val[rs] = val[rs] * tag[p];
    tag[ls] = tag[ls] * tag[p];
    tag[rs] = tag[rs] * tag[p];
    tag[p].init(2,2);
    tag[p].reset();
}
inline void build(int p,int l,int r) {
    val[p].l = 1,val[p].r = 2;
    tag[p].init(2,2);
    tag[p].reset();
    if (l == r) {
        if (c[l] == 1) {
            val[p].a[1][1] = 0,val[p].a[1][2] = 1;
        }else if(c[l] == 2) {
            val[p].a[1][1] = 1,val[p].a[1][2] = 1;
        }else{
            val[p] = fst*binpow(tr,c[l]-2);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int s,int e,matrix v,int l,int r) {
    if (s <= l && r <= e) {
        val[p] = val[p] * v;
        tag[p] = tag[p] * v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p] != qwq) pushdown(p);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return val[p].a[1][2];
    }
    int mid = (l + r) >> 1;
    if (l != r && tag[p] != qwq) pushdown(p);
    int ret = 0;
    if (s <= mid) ret = (ret+query(ls,s,e,l,mid))%mod;
    if (e > mid) ret = (ret+query(rs,s,e,mid+1,r))%mod;
    return ret;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
signed main () {
    #ifdef LOCAL
        freopen("D:/codes/exe/a.in","r",stdin);
        freopen("D:/codes/exe/a.out","w",stdout);
    #endif
    fst.init(1,2),tr.init(2,2),qwq.init(2,2);
    fst.a[1][1] = 1;
    fst.a[1][2] = 1;
    tr.a[1][1] = 0,tr.a[1][2] = 1;
    tr.a[2][1] = 1,tr.a[2][2] = 1;
    qwq.reset();
    n = read(),m = read();
    for (int i = 1; i <= n; i++) c[i] = read();
    build(1,1,n);
    while (m--) {
        int op,l,r;
        op=read(),l = read(),r = read();
        if (op == 1) {
            int x;
            x = read();
            matrix t = binpow(tr,x);
            modify(1,l,r,t,1,n);
        }else{
            write(query(1,l,r,1,n)%mod);
            puts("");
        }
    }
    return 0;
}