#include <bits/stdc++.h>
const int maxn = 1.5e3+20;
using namespace std;
int n;
vector<int> e[maxn];
int c[maxn];
inline void read(int &x) {
    x=0;
    int f=1;char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f=-1;
        ch=getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
int f[maxn][3];
void dfs(int u,int fa) {
    f[u][0]=c[u],f[u][2]=0;
    int sum = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs(v,u);
        f[u][0]+=min(f[v][0],min(f[v][1],f[v][2]));
        sum += min(f[v][1],f[v][0]);
        f[u][2]+=min(f[v][0],f[v][1]);
    }
    f[u][1] = 0x3f3f3f3f;
    for (auto v : e[u]) {
        if (v == fa) continue;
        if (f[v][0]>f[v][1]) {
            f[u][1] = min(f[u][1],sum-f[v][1]+f[v][0]);
        }else{
            f[u][1] = sum;
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) {
        int t,cnt;
        read(t);
        read(c[t]);
        read(cnt);
        for (int j = 1; j <= cnt; j++) {
            int x;
            read(x);
            e[t].push_back(x);
            e[x].push_back(t);
        }
    }
    memset(f,0x3f,sizeof(f));
    dfs(1,0);
    // for (int i = 1; i <= n; i++) {
    //     printf("%d %d %d\n",f[i][0],f[i][1],f[i][2]);
    // }
    
    printf("%d",min(f[1][0],f[1][1]));
    return 0;
}