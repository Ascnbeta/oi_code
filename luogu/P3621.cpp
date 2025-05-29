#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
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
int n;
vector<int> e[maxn<<1];
int tot,ans;
int dep[maxn<<1],minn=0x3f3f3f3f,maxx=0;
void dfs1(int u,int fa) {
    dep[u]=dep[fa]+1;
    int cnt = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        dfs1(v,u);
        ++cnt;
    }
    if (!cnt) {
        minn = min(dep[u],minn);
        maxx = max(dep[u],maxx);
    }
}
inline int dfs2(int u,int fa) {
    int c[3],cnt = 0;
    for (auto v : e[u]) {
        if (v == fa) continue;
        c[++cnt] = dfs2(v,u);
    }
    if (!cnt) {
        if (dep[u] == minn) return 0;
        if (dep[u] == maxx) return 1;
    }else{
        if ((c[1] == 0 && c[2] == 1) || (c[1] == 2 && c[2] == 1) || (c[1] == 0 && c[2] == 2)) ++ans;
        if (c[1] == 2 && c[2] == 2) {
            puts("-1");
            exit(0);
        }
        if (c[1] == 2 || c[2] == 2) {
            return 2;
        }
        if (c[1]+c[2] == 1) return 2;
        if (c[1]+c[2] == 0) return 0;
        else return 1;
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    tot = n;
    for (int i = 1; i <= n; i++) {
        int x,y;
        read(x),read(y);
        if (x==-1) {
            e[i].push_back(++tot);
            e[tot].push_back(i);
        }else{
            e[i].push_back(x);
            e[x].push_back(i);
        }
        if (y==-1) {
            e[i].push_back(++tot);
            e[tot].push_back(i);
        }else{
            e[i].push_back(y);
            e[y].push_back(i);
        }
    }
    dfs1(1,0);
    if (maxx-minn>1) {
        puts("-1");
        return 0;
    }else if(maxx == minn) {
        puts("0");
        return 0;
    }
    int x = dfs2(1,0);
    printf("%d",ans);
    return 0;
}