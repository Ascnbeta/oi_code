#include <bits/stdc++.h>
using namespace std;
template <typename T> 
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {
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
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 3e5+5;
int n,m;
struct op{
    int tp,x,y;
}q[maxn];
int* father=new int[maxn<<1],val[maxn<<1],tot;
vector<int> e[maxn<<1];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y,int id) {
    int p = find(x),q = find(y);
    if (p == q) return;
    ++tot;
    father[tot] = tot,val[tot] = id;
    father[p] = father[q] = tot;
    e[tot].push_back(p),e[tot].push_back(q);
}
int dfn[maxn<<1],out[maxn<<1],*idx=new int[maxn<<1],cnt,f[maxn<<1][20];
void dfs1(int u,int fa) {
    dfn[u] = ++cnt;
    idx[cnt] = u;
    for (auto v : e[u]) {
        if (v == fa) continue;
        f[v][0] = u;
        dfs1(v,u);
    }
    out[u] = cnt;
}
void pre() {
    for (int i = 1; i <= __lg(tot); i++) {
        for (int j = 1; j <= tot; j++) {
            f[j][i] = f[f[j][i-1]][i-1];
        }
    }
}
#define ls p<<1
#define rs p<<1|1
struct node{
    int val,tag;
}tr[maxn<<3];
inline void pushup(int p) {
    tr[p].val = max(tr[ls].val,tr[rs].val);
}
inline void pushdown(int p) {
    tr[ls].val += tr[p].tag;
    tr[rs].val += tr[p].tag;
    tr[ls].tag += tr[p].tag;
    tr[rs].tag += tr[p].tag;
    tr[p].tag = 0;
}
inline void build(int p,int l,int r) {
    if (l == r) {
        if (idx[l] <= n) tr[p].val = val[idx[l]];
        else tr[p].val = -1e9;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(p);
}
inline void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) {
        tr[p].val += v;
        tr[p].tag += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (l != r && tr[p].tag) pushdown(p);
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) return tr[p].val;
    int mid = (l + r) >> 1;
    if (l != r && tr[p].tag) pushdown(p);
    int ret = -1e9;
    if (s <= mid) ret = max(ret,query(ls,s,e,l,mid));
    if (e > mid) ret = max(ret,query(rs,s,e,mid+1,r));
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(val[i]),father[i]=i;
    tot = n;
    read(m);
    for (int i = 1; i <= m; i++) {
        string tp;int x,y;
        cin >> tp;
        assert((tp[0]=='U'||tp[0]=='A'||tp[0]=='F')&&(tp.size()==1||tp[1]=='1'||tp[1]=='2'||tp[1]=='3'));
        if (tp[0] == 'U') {
            read(x),read(y);
            q[i]={1,x,y};
            merge(x,y,i);
        }else if(tp[0] == 'A') {
            if (tp[1] == '1') {
                read(x),read(y);
                q[i]={2,x,y};
            }else if(tp[1] == '2') {
                read(x),read(y);
                q[i]={3,x,y};
            }else{
                read(x);
                q[i]={4,x};
            }
        }else{
            if (tp[1] == '1') {
                read(x);
                q[i]={5,x};
            }else if(tp[1] == '2') {
                read(x);
                q[i]={6,x};
            }else{
                q[i]={7};
            }
        }
    }
    delete[] father;
    for (int i = tot; i >= 1; i--) {
        if (!dfn[i]) dfs1(i,0);
    }
    assert(cnt==tot);
    pre();
    build(1,1,tot);
    delete[] idx;
    val[0] = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        if (q[i].tp == 2) {
            int x = q[i].x,v = q[i].y;
            modify(1,dfn[x],dfn[x],v,1,tot);
        }else if(q[i].tp == 3) {
            int x = q[i].x,v = q[i].y;
            for (int j = __lg(tot); j >= 0; j--) {
                if (val[f[x][j]] > i) continue;
                x = f[x][j];
            }
            modify(1,dfn[x],out[x],v,1,tot);
        }else if (q[i].tp == 4) {
            modify(1,1,tot,q[i].x,1,tot);
        }else if (q[i].tp == 5) {
            write(query(1,dfn[q[i].x],dfn[q[i].x],1,tot));
            putchar('\n');
        }else if (q[i].tp == 6) {
            int x = q[i].x;
            for (int j = __lg(tot); j >= 0; j--) {
                if (val[f[x][j]] > i) continue;
                x = f[x][j];
            }
            write(query(1,dfn[x],out[x],1,tot));
            putchar('\n');
        }else if (q[i].tp == 7) {
            write(query(1,1,tot,1,tot));
            putchar('\n');
        }
    }
    return 0;
}