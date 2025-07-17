#include <cstdio>
#include <cstring>
#include <assert.h>
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
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 2e5+5;
struct matrix {
    int n,m;ll data[4][4];
    matrix() {
        memset(data,0,sizeof(data));
    }
    matrix(int _n,int _m) {
        n = _n,m = _m;
        memset(data,0,sizeof(data));
    }
    inline void reset() {
        for (int i = 1; i <= n; i++) data[i][i] = 1;
    }
    ll* operator [] (int p) {
        return data[p];
    }
    matrix operator * (matrix &y) const{
        assert(m==y.n);
        matrix c(n,m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    c[i][j] += data[i][k]*y[k][j];
                }
            }
        }
        return c;
    }
}t1(3,3),t2(3,3),ans(1,3),un(3,3),t[maxn<<2];
inline void init() {
    t1[1][1] = t1[2][1] = t1[2][2] = t1[3][1] = t1[3][2] = t1[3][3] = 1;
    t2[1][1] = t2[3][1] = t2[3][2] = t2[3][3] = 1;
    ans[1][1] = ans[1][2] = ans[1][3] = 1;
    un[1][1] = un[2][2] = un[3][3] = 1;
}
#define ls p<<1
#define rs p<<1|1
inline void pushup(int p) {
    t[p] = t[ls] * t[rs];
}
inline void build(int p,int l,int r) {
    if (l == r) {
        t[p] = un;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
int tp[maxn];
inline void modify(int p,int pos,int v,int l,int r) {
    if (l == r) {
        if (v > 0) t[p] = un;
        else if (v == -1) t[p] = t1;
        else if(v == -2) t[p] = t2;
        tp[l] *= -1;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,v,l,mid);
    else modify(rs,pos,v,mid+1,r);
    pushup(p);
}
int n;
int d[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    init();
    build(1,1,n);
    for (int i = 1; i <= n; i++) {
        int op;read(op);
        if (op != 3) {
            tp[i] = -op;
            d[i] = i;
            modify(1,i,tp[i],1,n);
        }else{
            int x;read(x);
            d[i] = d[x];
            modify(1,d[i],tp[d[i]],1,n);
        }
        write((ans*t[1])[1][1]);putchar('\n');
    }
    return 0;
}