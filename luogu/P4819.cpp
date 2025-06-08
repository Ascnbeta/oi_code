#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int n,m;
vector<int> e[maxn],e1[maxn];
int ind[maxn],siz[maxn];
inline void read(int &x) {
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
int dfn[maxn],low[maxn],cnt;bool instk[maxn];
stack<int> st;
int scc[maxn],sc;
void tarjan(int u) {
    dfn[u]=low[u]=++cnt;
    instk[u] = true;
    st.push(u);
    for (auto v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }else if(instk[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++sc;
        while (!st.empty()) {
            scc[st.top()] = sc;
            siz[sc]++;
            instk[st.top()] = false;
            if (st.top() == u) {
                st.pop();
                break;
            }
            st.pop();
        }
    }
}
map<int,int> mp[maxn];
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    bool flag = false;
    for (int u = 1; u <= n; u++) {
        for (int v : e[u]) {
            if (scc[u] == scc[v]) continue;
            if (mp[scc[u]].find(scc[v]) != mp[scc[u]].end()) continue;
            ++ind[scc[v]];
            mp[scc[u]][scc[v]] = 1;
            e1[scc[u]].push_back(scc[v]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= sc; i++) {
        if (ind[i] == 0) {
            if (siz[i] == 1) {
                flag = true;
                for (auto v : e1[i]) {
                    if (ind[v] == 1) {
                        flag = false;
                        break;
                    }
                }
            }
            ++ans;
        }
    }
    if (flag) printf("%.6f",1.00*1-1.00*(ans-1)/n);
    else printf("%.6f",1.00*1-1.00*ans/n);
    return 0;
}