#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e6+30;
int n;
int tr[maxn][26],fail[maxn],e[maxn],tot;
string t,s;
inline void insert(string a) {
    int p = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!tr[p][a[i]-'a']) tr[p][a[i]-'a'] = ++tot;
        p = tr[p][a[i]-'a'];
    }
    e[p]++;
}
inline void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) if(tr[0][i]) q.push(tr[0][i]);
    while (!q.empty()) {
        int u = q.front();q.pop();
        for (int i = 0; i < 26; i++) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            }else{
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}
inline int query(string a) {
    int ret = 0;
    int p = 0;
    for (int i = 0; i < a.size(); i++) {
        p = tr[p][a[i]-'a'];
        for (int j = p; j && ~e[j]; j = fail[j]) ret += e[j],e[j] = -1;
    }
    return ret;
}
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert(s);
    }
    build();
    cin >> t;
    cout << query(t) << '\n';
    return 0;
}