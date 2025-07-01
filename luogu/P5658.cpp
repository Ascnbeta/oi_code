#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5+5;
int n,father[maxn];
char s[maxn];
vector<int> e[maxn];
ll f[maxn][2];
int st[maxn],top;
void dfs(int u,int fa) {
    int ret = 0,tmp = 0;bool flag = false;
    if (s[u] == '(') {
        st[++top] = u;
        f[u][1] = 0;
    }else{
        if (top == 0) {
            f[u][1] = 0;
        }else{
            flag = true;
            tmp = st[top--];
            f[u][1] = f[father[tmp]][1]+1ll;
        }
    }
    ret = top;
    f[u][0] = f[fa][0] + f[fa][1];
    for (auto &v : e[u]) {
        dfs(v,u);
        top = ret;
    }
    if (flag) st[++top] = tmp;
}
ll ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 2; i <= n; i++) {
        int x;cin >> x;
        father[i] = x;
        e[x].push_back(i);
    }
    dfs(1,0);
    for (int i = 1; i <= n; i++) ans ^= 1ll*i*(f[i][0]+f[i][1]);
    cout << ans << '\n';
    return 0;
}