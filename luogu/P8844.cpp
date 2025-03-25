#include <bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
const int maxn = 1e5+30;
int n,m;
vector<int> e[maxn],dep[maxn];
struct op{
    int d,id;
    vector<int> q,ans;
}o[maxn];
int cnt;
int dfn[maxn],in[maxn],out[maxn],tot,maxx;
void dfs(int u,int fa,int d) {
    maxx = max(maxx,d+1);
    dep[d+1].push_back(u);
    dfn[++tot] = u;
    in[u] = tot;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u,d+1);
    }
    out[u] = tot;
}
int sum[maxn<<2];
inline void pushup(int p) {
    sum[p] = sum[ls] + sum[rs];
}
inline void modify(int p,int pos,int l,int r) {
    if (l == r) {
        sum[p] += 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(ls,pos,l,mid);
    else modify(rs,pos,mid+1,r);
    pushup(p);
}
inline int query(int p,int s,int e,int l,int r) {
    if (s <= l && r <= e) {
        return sum[p];
    } 
    int mid = (l + r) >> 1;
    int ret = 0;
    if (s <= mid) ret += query(ls,s,e,l,mid);
    if (e > mid) ret += query(rs,s,e,mid+1,r);
    return ret; 
}
bool cmp1 (op x,op y) {
    return x.d > y.d;
}
bool cmp2 (op x,op y) {
    return x.id < y.id;
}
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0,0);
    // for (int i = 1; i <= n; i++) {
    //     for (int j : dep[i]) cout << j << ' ';
    //     cout << '\n';
    // }
    for (int i = 1; i <= m; i++) {
        int op,x;
        cin >> op >> x;
        if (op == 1) {
            ++cnt;
            o[cnt].d = x;
            o[cnt].id = cnt;
        }else if (op == 2) {
            if (cnt == 0) {
                cout << 0 << '\n';
                continue;
            }
            o[cnt].q.push_back(x);
        }
    }
    sort(o+1,o+cnt+1,cmp1);
    int lst = maxx+1;
    for (int i = 1; i <= cnt; i++) {
        while (lst > o[i].d) {
            --lst;
            for (auto j : dep[lst]) {
                modify(1,in[j],1,n);
            }
        }
        for (int j = 0; j < o[i].q.size(); j++) {
            o[i].ans.push_back(query(1,in[o[i].q[j]],out[o[i].q[j]],1,n));
        }
    }
    // cout << maxx << '\n';
    sort(o+1,o+cnt+1,cmp2);
    for (int i = 1; i <= cnt; i++) {
        for (auto j : o[i].ans) cout << j << '\n';
    }
    return 0;
}