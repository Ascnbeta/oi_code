#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n;
int w[maxn],ls[maxn],rs[maxn];
int st[maxn],top;
void dfs(int u) {
    cout << u << ' ';
    if (ls[u]) dfs(ls[u]);
    if (rs[u]) dfs(rs[u]);
}
int root;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        w[x] = i;
        if (i == 1) root = x;
    }
    for (int i = 1; i <= n; i++) {
        int tmp = top;
        while (tmp&&w[st[tmp]]>w[i]) --tmp;
        if (tmp) rs[st[tmp]] = i;
        if (tmp < top) ls[i] = st[tmp+1];
        st[++tmp] = i;
        top = tmp;  
    }
    dfs(root);
    return 0;
}