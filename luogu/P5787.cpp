#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 2e5+5;
int n,m,k;
int father[maxn<<1],rk[maxn<<1];
struct opt{int x,y,d;}st[maxn<<2];int top;
struct edge{
    int u,v;
}e[maxm];
#define ls p<<1
#define rs p<<1|1
vector<int> t[maxn<<2];
inline int find(int x) {
    while (x != father[x]) x = father[x];
    return x;
}
inline void merge(int u,int v) {
    int p = find(u),q = find(v);
    if (rk[p]<rk[q]) swap(p,q);
    st[++top] = {q,p,rk[p]==rk[q]};
    father[q] = p;
    rk[p] = max(rk[p],rk[q]+1);
}
void modify(int p,int s,int e,int v,int l,int r) {
    if (s <= l && r <= e) return t[p].push_back(v),void();
    int mid = (l + r) >> 1;
    if (s <= mid) modify(ls,s,e,v,l,mid);
    if (e > mid) modify(rs,s,e,v,mid+1,r);
}
void solve(int p,int l,int r) {
    int lasttop = top;bool f = true;
    for (int i : t[p]) {
        int u = e[i].u,v = e[i].v;
        if (find(u) == find(v)) {
            for (int j = l; j <= r; j++) {
                puts("No");
            }
            f = false;
            break;
        } 
        merge(u,v+n);
        merge(v,u+n);
    }
    if (f) {
        if (l == r) puts("Yes");
        else {
            int mid = (l + r) >> 1;
            solve(ls,l,mid),solve(rs,mid+1,r);
        }
    }
    while (top != lasttop) {
        father[st[top].x] = st[top].x;
        rk[st[top].y] -= st[top].d;
        top--;
    }
}

int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
        int l,r;
        cin >> l >> r;++l;
        modify(1,l,r,i,1,k);
    }
    for (int i = 1; i <= 2*n; i++) father[i] = i;
    solve(1,1,n);
    return 0;
}