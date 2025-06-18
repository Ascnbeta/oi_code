#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+30;
string s,T;
int n,m;
int tr[maxn][26],tr2[maxn][26],ed[maxn],fail[maxn],father[maxn],tot=1;
vector<int> e1[maxn];
inline void build() {
    queue<int> q;
    fail[1] = 1;
    for (int i = 0; i < 26; i++) {
        if (tr[1][i]) {
            fail[tr[1][i]] = 1;
            e1[1].push_back(tr[1][i]);
            e1[tr[1][i]].push_back(1);
            q.push(tr[1][i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();q.pop();
        for (int i = 0; i < 26; i++) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                if (fail[tr[u][i]] == 0) fail[tr[u][i]] = 1;
                e1[fail[tr[u][i]]].push_back(tr[u][i]);
                e1[tr[u][i]].push_back(fail[tr[u][i]]);
                q.push(tr[u][i]);
            }else{
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}
int dfn[maxn],out[maxn],cnt;
void dfs1(int u,int fa) {
    dfn[u] = ++cnt;
    for (auto v : e1[u]) {
        if (v == fa) continue;
        dfs1(v,u);
    }
    out[u] = cnt;
}
int t[maxn];
inline int lowbit(int x) {return x&-x;}
inline void modify(int p,int x) {
    while (p < n) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
struct task{
    int id,x;
};
vector<task> b[maxn]; 
struct ask{
    int x,y,ans;
}q[maxn];
void dfs2(int u) {
    modify(dfn[u],1);
    if (b[u].size() > 0) {
        for (auto i : b[u]) q[i.id].ans = query(out[i.x])-query(dfn[i.x]-1);
    }
    for (int i = 0; i < 26; i++) {
        if (tr2[u][i]) {
            dfs2(tr2[u][i]);
        }
    }
    modify(dfn[u],-1);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    int tmp = 0,p = 1;
    father[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B') {
            p = father[p]; 
        }else if(s[i] == 'P') {
            ed[++tmp] = p;
        }else{
            if (!tr[p][s[i]-'a']) tr[p][s[i]-'a'] = ++tot;
            father[tr[p][s[i]-'a']] = p;
            p = tr[p][s[i]-'a'];
        }
    }
    memcpy(tr2,tr,sizeof(tr));
    build();
    // for (int i = 1; i <= tot; i++) cout << fail[i] << ' ';
    // cout << '\n';
    dfs1(1,0);
    cerr << clock() << '\n';
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].x >> q[i].y;
        b[ed[q[i].y]].push_back({i,ed[q[i].x]});
    }
    cerr << clock() << '\n';
    dfs2(1);
    cerr << clock() << '\n';
    for (int i = 1; i <= m; i++) cout << q[i].ans << '\n';
    return 0;
}