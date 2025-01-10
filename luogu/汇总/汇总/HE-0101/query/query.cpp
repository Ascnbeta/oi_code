#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t,p) for(int i = s;i <= t;i += p)
#define drep(i,s,t,p) for(int i = s;i >= t;i -= p)
#ifdef LOCAL
    FILE *I = freopen("in.in","r",stdin),*O = freopen("out.out","w",stdout);
#else
    FILE *I = freopen("query.in","r",stdin),*O = freopen("query.out","w",stdout);
#endif
using ll = long long;using ull = unsigned long long;
using db = double;using ldb = long double;
const int N = 5e5 + 10;
struct node{int l,r,k,id;}q[N];
int n,m,d[N],tot;vector<int> e[N];
int st[20][N],lg[N];
int dep[N],siz[N],son[N],top[N],fa[N];
void dfs1(int x){
    dep[x] = dep[fa[x]] + 1;siz[x] = 1;
    for(auto y:e[x]){
        if(y == fa[x]) continue;
        fa[y] = x;dfs1(y);
        siz[x] += siz[y];
        if(siz[son[x]] < siz[y]) son[x] = y;
    }
}
void dfs2(int x,int t){
    top[x] = t;
    if(son[x]) dfs2(son[x],t);else return;
    for(auto y:e[x]){
        if(y == fa[x] || y == son[x]) continue;
        dfs2(y,y);
    }
}
inline int LCA(int x,int y){
    int fx = top[x],fy = top[y];
    while(fx != fy){
        if(dep[fx] < dep[fy]) swap(x,y),swap(fx,fy);
        x = fa[fx];fx = top[x];
    }
    if(dep[x] > dep[y]) swap(x,y);
    return x;
}
inline int qry(int l,int r){
    int k = lg[r-l+1];
    return LCA(st[k][l],st[k][r-(1<<k)+1]);
}
inline void solve1(){
    rep(now,1,m,1){
        int l = q[now].l,r = q[now].r,k = q[now].k;
        int ans = 0;
        rep(i,l+k-1,r,1)
            ans = max(ans,dep[qry(i-k+1,i)]);
        cout<<ans<<'\n';
    }    
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>n;
    rep(i,2,n,1) lg[i] = lg[i >> 1] + 1;
    rep(i,2,n,1){
        int u,v;cin>>u>>v;e[u].emplace_back(v);e[v].emplace_back(u);
        d[u]++;d[v]++;
    }
    bool flag1 = true;
    rep(i,2,n,1) flag1 &= (d[i] == 2);
    cin>>m;
    rep(i,1,m,1){
        cin>>q[i].l>>q[i].r>>q[i].k;q[i].id = i;
        tot += (q[i].r-q[i].l+1==q[i].k);
    }
    dfs1(1);dfs2(1,1);
    rep(i,1,n,1) st[0][i] = i;
    int t = lg[n];
    rep(j,1,t,1) rep(i,1,n-(1<<j)+1,1)
        st[j][i] = LCA(st[j-1][i],st[j-1][i+(1<<(j-1))]);
    return solve1(),0;
    puts("What Can I say?");
    //orz K8He,5k_sync_closer,jijidawang,ReTF,etc...
}