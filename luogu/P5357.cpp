#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5+30;
int n;
int tr[maxn][26],fail[maxn],e[maxn],tot;
int ind[maxn],ans[maxn];
string s,t;
inline void insert(string a,int id) {
    int p = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!tr[p][a[i]-'a']) tr[p][a[i]-'a'] = ++tot;
        p = tr[p][a[i]-'a'];
    }
    e[id] = p;
}
inline void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) if (tr[0][i]) q.push(tr[0][i]);
    while (!q.empty()) {
        int u = q.front();q.pop();
        for (int i = 0; i < 26; i++) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                ++ind[fail[tr[u][i]]];
                q.push(tr[u][i]);
            }else{
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}
inline void query(string a) {
    int p = 0;
    for (int i = 0; i < a.size(); i++) {
        p = tr[p][a[i]-'a'];
        ans[p]++;
    }
}
inline void topo() {
    queue<int> q;
    for (int i = 1; i <= tot; i++) if (!ind[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = fail[u];
        ans[v] += ans[u];
        --ind[v];
        if (ind[v] == 0) q.push(v);
    }
}
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        insert(t,i);
    }
    build();
    cin >> t;
    query(t);
    topo();
    for (int i = 1; i <= n; i++) cout << ans[e[i]] << '\n';
    return 0;
}