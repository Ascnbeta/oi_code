//wo shi sb,wo du cuo di le,11:15 cai fa xian,xing kui wo shi luan xu kai ti
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

#define N 100005
#define LL long long
#define MOD 1000000007

inline int R() {
    int x=0; bool f=0; char c=getchar();
    while (!isdigit(c)) f|=(c=='-'),c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    return f?-x:x;
}

template<typename T>
void W(T x,char Extra=0) {
    if (x<0) putchar('-'),x=-x; if (x>9) W(x/10);
    putchar(x%10+'0'); if (Extra) putchar(Extra);
}

using namespace std;
int n,m,v;
struct In {
    int c,d;
    inline bool operator<(const In tmp) const {
        return c^tmp.c?c<tmp.c:d<tmp.d;
    }
    inline bool operator==(const In tmp) const {
        return c==tmp.c and d==tmp.d;
    }
}a[N];

bool check() {
    for (int i=2;i<=m;i++)
        if (a[i].c==a[i-1].c) return 0;
    return 1;
}

LL quickpow(LL a,int k) {
    LL res=1;
    while (k) {
        if (k&1) res=res*a%MOD;
        a=a*a%MOD,k>>=1;
    }
    return res;
}

int main() {
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    int T=R();
    while (T--) {
        n=R(),m=R(),v=R();
        for (int i=1;i<=m;i++) a[i].c=R(),a[i].d=R();
        sort(a+1,a+m+1); m=unique(a+1,a+m+1)-a-1;
        if (!check()) { W(0,'\n'); continue; }
        LL ans=quickpow(1ll*v*v%MOD,a[1].c-1);
        for (int i=2;i<=m;i++)
            ans=(ans*(quickpow(1ll*v*v%MOD,a[i].c-a[i-1].c)-quickpow(v,a[i].c-a[i-1].c-1)*(v-1)%MOD+MOD)%MOD)%MOD;
        W(ans*quickpow(1ll*v*v%MOD,n-a[m].c)%MOD,'\n');
    }
    return 0;
}