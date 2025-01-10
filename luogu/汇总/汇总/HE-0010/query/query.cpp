bool M1;
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

#define N 500005

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
int n;

int cnt,head[N];
struct Node { int to,nxt; }e[N<<1];

void add(int u,int v) { e[++cnt]=Node{v,head[u]},head[u]=cnt; }

int siz[N],son[N],dep[N],fa[N];

void dfs1(int u,int Fa) {
    siz[u]=1,dep[u]=dep[fa[u]=Fa]+1;
    for (int i=head[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if (v==Fa) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if (siz[v]>siz[son[u]]) son[u]=v;
    }
}

int top[N],dfncnt,dfn[N],idfn[N];

void dfs2(int u,int Top) {
    top[u]=Top,dfn[u]=++dfncnt,idfn[dfncnt]=u;
    if (son[u]) dfs2(son[u],Top);
    for (int i=head[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if (v==fa[u] or v==son[u]) continue;
        dfs2(v,v);
    }
}

int LCA(int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

struct Data {
    int id;
    inline bool operator<(const Data tmp) const {
        return dep[id]^dep[tmp.id]?dep[id]<dep[tmp.id]:dfn[id]<dfn[tmp.id];
    }
}St[20][N];

void init() {
    for (int i=1;i<=n;i++) St[0][dfn[i]]=Data{i};
    for (int i=1;i<20;i++)
        for (int j=1;j+(1<<i)-1<=n;j++)
            St[i][j]=min(St[i-1][j],St[i-1][j+(1<<(i-1))]);
}

inline int getLCA(int u,int v) {
    u=dfn[u],v=dfn[v];
    if (u>v) swap(u,v); ++u;
    if (u>v) return idfn[v];
    int k=__lg(v-u+1);
    return fa[min(St[k][u],St[k][v-(1<<k)+1]).id];
}

int st[20][N];

void init0() {
    for (int i=1;i<=n;i++) st[0][i]=i;
    for (int i=1;i<20;i++)
        for (int j=1;j+(1<<i)-1<=n;j++)
            st[i][j]=getLCA(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}

inline int getSquLCA(int l,int r) {
    int k=__lg(r-l+1);
    return getLCA(st[k][l],st[k][r-(1<<k)+1]);
}

int d[N];

bool check() {
    for (int i=1;i<=n;i++)
        if (d[i]>2) return 0;
    return 1;
}

struct PT {
    int tcnt,rt[N];
    struct Data { int sum,mx,lmx,rmx; };
    struct Tree { Data val; int ls,rs; }t[N<<6];

    inline Data pushup(Data a,Data b) {
        Data res;
        res.sum=a.sum+b.sum;
        res.lmx=max(a.lmx,a.sum+b.lmx);
        res.rmx=max(b.rmx,b.sum+a.rmx);
        res.mx=max({a.mx,b.mx,a.rmx+b.lmx});
        return res;
    }

    void upd(int &x,int y,int l,int r,int pos) {
        t[x=++tcnt]=t[y];
        if (l==r) return t[x]={1,1,1,1,0,0},void();
        int mid=(l+r>>1);
        if (pos<=mid) upd(t[x].ls,t[y].ls,l,mid,pos);
        else upd(t[x].rs,t[y].rs,mid+1,r,pos);
        t[x].val=pushup(t[t[x].ls].val,t[t[x].rs].val);
    }

    Data ask(int x,int l,int r,int L,int R) {
        if (!x) return {0,0,0,0};
        if (L<=l and r<=R) return t[x].val;
        int mid=(l+r>>1);
        if (R<=mid) return ask(t[x].ls,l,mid,L,R);
        else if (L>mid) return ask(t[x].rs,mid+1,r,L,R);
        else return pushup(ask(t[x].ls,l,mid,L,R),ask(t[x].rs,mid+1,r,L,R));
    }
}pt;

void sol() {
    dfs1(1,0); dfs2(1,1);
    for (int i=n;i;i--) pt.upd(pt.rt[i],pt.rt[i+1],1,n,idfn[i]);
    int q=R();
    for (int i=1;i<=q;i++) {
        int l=R(),r=R(),k=R();
        int ll=1,rr=n,res=0;
        while (ll<=rr) {
            int mid=(ll+rr>>1);
            if (pt.ask(pt.rt[mid],1,n,l,r).mx>=k) ll=mid+1,res=mid;
            else rr=mid-1;
        }
        W(dep[idfn[res]],'\n');
    }
}

bool M2;

int main() {
    // cerr<<(&M2-&M1)/1024.0/1024;
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=R();
    for (int i=1;i<n;i++) {
        int u=R(),v=R();
        add(u,v),add(v,u);
        d[u]++,d[v]++;
    }
    if (check()) return sol(),0;
    dfs1(1,0); dfs2(1,1);
    init(); init0();
    int q=R();
    for (int i=1;i<=q;i++) {
        int l=R(),r=R(),k=R(),res=0;
        for (int j=l;j+k-1<=r;j++) {
            int tmp=getSquLCA(j,j+k-1);
            if (!res or dep[tmp]>dep[res]) res=tmp;
        }
        W(dep[res],'\n');
    }
    return 0;
}