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
int n,k,id[N];
struct Edge { int u,v; }edge[N];

int cnt,head[N];
struct Node { int to,nxt; }e[N<<1];

void add(int u,int v) { e[++cnt]=Node{v,head[u]},head[u]=cnt; }

LL quickpow(LL a,int k) {
    LL res=1;
    while (k) {
        if (k&1) res=res*a%MOD;
        a=a*a%MOD,k>>=1;
    }
    return res;
} LL fac[N],ifac[N];

LL C(int n,int m) { return n<0 or m<0 or n<0?0:fac[n]*ifac[n-m]%MOD*ifac[m]%MOD; }

LL f[N];

void dfs(int u,int Fa) {
    f[u]=1; int cnt=0;
    for (int i=head[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if (v==Fa) continue;
        dfs(v,u);
        f[u]=f[u]*f[v]%MOD,++cnt;
    }
    f[u]=f[u]*fac[cnt]%MOD;
}

int main() {
    freopen("traverse.in","r",stdin);
    freopen("traverse.out","w",stdout);
    int c=R(),T=R();
    fac[0]=1;
    for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%MOD;
    ifac[N-1]=quickpow(fac[N-1],MOD-2);
    for (int i=N-2;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%MOD;
    while (T--) {
        n=R(),k=R();
        cnt=0; memset(head,0,(n+1)*sizeof(head[0]));
        for (int i=1;i<n;i++) {
            int u=R(),v=R();
            add(u,v),add(v,u);
            edge[i]=Edge{u,v};
        }
        for (int i=1;i<=k;i++) id[i]=R();
        if (c==18) { W(1,'\n'); continue; }
        if (c==19 or c==20) {
            if (n==2) W(1,'\n');
            else if (n==3) W(1,'\n');
            else W((k*fac[n-2]%MOD-(1ll*k*(k-1)/2)%MOD*fac[n-3]%MOD+MOD)%MOD,'\n');
            continue;
        }
        LL ans=0;
        for (int i=1;i<=k;i++) {
            dfs(edge[id[i]].u,edge[id[i]].v);
            dfs(edge[id[i]].v,edge[id[i]].u);
            (ans+=f[edge[id[i]].u]*f[edge[id[i]].v]%MOD)%=MOD;
        }
        W(ans,'\n');
    }
    return 0;
}
//bx chuan qi zhuang ban wang HDK