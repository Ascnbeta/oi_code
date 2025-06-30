#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int n,m;
vector<int> e[maxn],ans;
struct edge{
    int to,nxt;
}e1[maxn<<1];
int head[maxn],tot=1;
inline void add(int u,int v) {
    e1[++tot].to = v;
    e1[tot].nxt = head[u];
    head[u] = tot;
}
void dfs(int u,int fa) {
    ans.push_back(u);
    for (auto &v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
    }
}
int dfn[maxn],low[maxn],cnt;bool cut[maxn<<1];
void tarjan(int u,int pre) {
    dfn[u] = low[u] = ++cnt;
    for (int i = head[u]; i; i = e1[i].nxt) {
        int v = e1[i].to;
        if (v == pre) continue;
        if (!dfn[v]) {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
        }else{
            low[u] = min(low[u],dfn[v]);
        }
        if (dfn[u] < low[v]) {
            cut[i] = cut[i^1] = true;
        }
    }
}
void dfs2(int u,int b) {
    dfn[u] = b,low[b]++;
    for (int i = head[u]; i; i = e1[i].nxt) {
        int v = e1[i].to;
        if (cut[i] || dfn[v]) continue;
        dfs2(v,b);
    }
}
int tmp;bool temp;
void dfs3(int u) {
    ans.push_back(u);
    head[u] = 1;
    if (low[dfn[u]] == 1) {
        for (auto &v : e[u]) {
            if (head[v]) continue;
            dfs3(v);
        }
    }else{
        bool flag = false;
        for (int i = 0; i < e[u].size(); ++i) {
            if (temp) break;
            int v = e[u][i];
            if (head[v]) continue;
            if (dfn[u] == dfn[v]) {
                ++i;
                while (i<e[u].size()&&head[e[u][i]]) ++i;
                if (i!=e[u].size()) {
                    tmp = e[u][i];
                }else if(v > tmp) {
                    temp = true;
                    flag = true;
                }
                break;
            }
        }
        for (int i = 0; i < e[u].size(); ++i) {
            int v = e[u][i];
            if (head[v]) continue;
            if (dfn[v] == dfn[u] && flag) continue;
            dfs3(v);
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    if (m == n-1) {
        for (int i = 1; i <= m; i++) {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) sort(e[i].begin(),e[i].end());
        dfs(1,0);
        for (int &i : ans)  cout << i << ' ';
    }else{
        for (int i = 1; i <= m; i++) {
            int u,v;
            cin >> u >> v;
            add(u,v),add(v,u);
        }
        tarjan(1,0);
        cnt = 0;
        memset(dfn,0,sizeof(dfn));//回收空间，dfn->bel
        memset(low,0,sizeof(low));//回收空间，low->siz
        for (int i = 1; i <= n; i++) {
            if (!dfn[i]) ++cnt,dfs2(i,cnt);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = head[i]; j; j = e1[j].nxt) {
                int v = e1[j].to;
                e[i].push_back(v);
            }
            sort(e[i].begin(),e[i].end());
        }
        memset(head,0,sizeof(head));//回收空间，head->vis
        dfs3(1);
        assert(ans.size()==n);
        for (int &i : ans)  cout << i << ' ';
    }
    
    return 0;
}