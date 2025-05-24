#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.5e3+30;
inline void read(int &x) {
    x=0;
    int f=1;char ch=getchar();
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
int n;
int s[maxn];
vector<int> e[maxn];
int f[maxn][2];
void dfs(int u,int fa) {
    f[u][0] = 0;
    f[u][1] = s[u];
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
        if (f[v][1] > 0) f[u][1] += f[v][1];
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) {
        int u=0;
        read(u);
        e[u].push_back(i);
    }
    read(n);
    for (int i = 1; i <= n; i++) read(s[i]);
    read(n);
    for (int i = 1; i <= n; i++) {
        int x=0;
        read(x);
        s[i]=x-s[i];
    }
    dfs(0,0);
    printf("%d",max(f[0][0],f[0][1]));
    return 0;
}