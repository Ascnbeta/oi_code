#include <bits/stdc++.h>
using namespace std;
int n;
int ind[53];bool f[53];
vector<int> e[53];
int x,tot;
struct node{
    int id,c;
    bool operator < (const node &y) const {
        return c < y.c;
    }
}v[53],vsc[53];
int dfn[53],low[53],cnt;
bool instk[53];int st[53],top;
int sc,scc[53],minn[53],minid[53];
inline void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    st[++top] = u;instk[u] = true;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(instk[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++sc;
        while (1) {
            int tmp = st[top--];
            scc[tmp] = sc;
            if (v[tmp].c < minn[sc]) minn[sc] = v[tmp].c,minid[sc] = tmp;
            instk[tmp] = false;
            if (tmp == u) break; 
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i].c,v[i].id = i,minn[i] = 0x3f3f3f3f;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            cin >> ch;
            if (ch == 'Y') e[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= sc; i++) vsc[i].id = minid[i],vsc[i].c = minn[i];
    for (int i = 1; i <= n; i++) {
        for (auto j : e[i]) {
            if (scc[i] == scc[j]) continue;
            ++ind[scc[j]];
        }
    }
    for (int i = 1; i <= sc; i++) if(!ind[i]) ++tot,x += vsc[i].c,f[vsc[i].id] = true;
    sort(v+1,v+n+1);
    for (int i = 1; i <= n; i++) {
        if (f[v[i].id]) continue;
        if (1.0*x/tot > v[i].c) {
            ++tot,x += v[i].c,f[v[i].id] = true;
        }
    }
    printf("%.15f",1.0*x/tot);
    return 0;
}