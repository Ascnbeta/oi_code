#include <bits/stdc++.h>
typedef long long ll;
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
const int maxn = 1e5+30;
const int maxm = 4e4+30;
int n,m,q;
struct edge{
    int to,nxt;ll w;
}e[maxm<<1],e1[maxm<<1];
int head[maxn],head1[maxn<<1],tot,tot1;
inline void add(int u,int v,int w,int pos) {
    if (pos == 0) {
        e[++tot].to = v;
        e[tot].w = w;
        e[tot].nxt = head[u];
        head[u] = tot;
    }else{
        e1[++tot1].to = v;
        e1[tot1].w = w;
        e1[tot1].nxt = head1[u];
        head1[u] = tot1;
    }
}
int dfn[maxn],low[maxn],cnt;
int st[maxn],top;
ll ans;
ll lval[maxn],dis[maxn];//lval[u]指low[u]最后可能更新的边，dis[u]是树上1->u距离。
//如果出现点双，栈顶的点的lval+dis[u->栈顶]就是环长
int sq;ll len[maxn<<1];//len环长
void tarjan(int u,int fa) {
    dfn[u] = low[u] = ++cnt;
    st[++top] = u;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;ll w = e[i].w;
        if (v == fa) continue;
        if (!dfn[v]) {
            lval[v] = w;
            dis[v] = dis[u] + w;
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v] >= dfn[u]) {
                ++sq;
                len[sq] = lval[st[top]]+dis[st[top]]-dis[u];
                int tmp;
                do {
                    tmp = st[top--];
                    ll l = dis[tmp]-dis[u];
                    l = min(l,len[sq]-l);
                    add(tmp,sq,l,1),add(sq,tmp,l,1);
                }while(tmp != v);
                add(u,sq,0,1),add(sq,u,0,1);
            }
        }else if(dfn[v] < dfn[u]) {
            lval[u] = w,low[u] = min(low[u],dfn[v]);
        }
    }
    //连通图不用特判根节点
}
int f[maxn][20],dep[maxn];ll dis1[maxn];//f=father,dep指圆方树上深度,dis1指圆方树上到根距离
void dfs(int u,int fa) {
    dep[u] = dep[fa] + 1;
    for (int i = 1; i <= __lg(sq); i++) f[u][i] = f[f[u][i-1]][i-1];
    for (int i = head1[u]; i; i = e1[i].nxt) {
        int v = e1[i].to;ll w = e1[i].w;
        if (v == fa) continue;
        dis1[v] = dis1[u] + w;
        f[v][0] = u;
        dfs(v,u);
    }
}
inline pair<int,int> getlca(int u,int v) {
    if (dep[u] > dep[v]) swap(u,v);
    for (int i = __lg(sq); i >= 0; i--) {
        if (dep[f[v][i]] >= dep[u]) v = f[v][i];
    }
    if (u == v) return {u,-1};
    for (int i = __lg(sq); i >= 0; i--) {
        if (f[u][i] != f[v][i]) u = f[u][i],v = f[v][i];
    }
    if (f[u][0] <= n) return {f[u][0],-1};//lca是圆点返回-1
    else return {u,v};//方点则要对方点所在的环做特判
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m),read(q);
    sq = n;
    for (int i = 1; i <= m; i++) {
        int u,v,w;
        read(u),read(v),read(w);
        add(u,v,w,0);
        add(v,u,w,0);
    }
    tarjan(1,0);
    // for (int i = 1; i <= sq; i++) {
    //     for (int j = head1[i]; j; j = e1[j].nxt) {
    //         cout << i << ' ' << e1[j].to << '\n';
    //     }
    // }
    dfs(1,0);//预备倍增lca，倍增回答询问好写一些。
    while (q--) {
        int u,v;
        read(u),read(v);
        pair<int,int> lca = getlca(u,v);
        if (lca.second == -1) write(dis1[u]+dis1[v]-2*dis1[lca.first]),putchar('\n');//lca是圆点直接按照式子走就行
        else {
            int x=lca.first,y=lca.second;
            ll tmp = llabs(dis[x]-dis[y]);//lca两个圆儿子距环上根的距离，由于是dfs求出来的所以是同一个顺序的距离，可以直接减出u->v的距离
            tmp = min(tmp,len[f[x][0]]-tmp);//环长减去tmp可以得到u->v另一个方向的距离，取min
            write(dis1[u]+dis1[v]-dis1[x]-dis1[y]+tmp);putchar('\n');//删去lca到根的距离同时减掉两个圆儿子到lca的树上权，再补回tmp            
        }
    }
    return 0;
}