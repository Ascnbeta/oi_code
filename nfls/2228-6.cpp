#include <bits/stdc++.h>
using namespace std;
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
const int maxn = 530;
const int maxm = maxn*maxn;
int n,m;
int e[maxn][maxn];
bool vis[maxn];
int t1,t2;
int tot,siz[maxn],bel[maxn],dis[maxn];
char s[maxn];
int ch[maxn];
int father[maxn];
void dfs (int u,int cnt,int p,int fa) {
    dis[u] = cnt;
    ++siz[p];bel[u] = p;
    vis[u] = true;
    if (cnt % 2 == 1) father[u] = t1;
    else if(!t2) father[u] = u,t2 = u;
    else father[u] = t2;
    for (int i = 1; i <= n; i++) {
        if (e[u][i] == 0 && i != fa) {
            if (vis[i]) {
                if ((dis[u]-dis[i]) % 2 == 0) {
                    puts("No");
                    exit(0);
                }
            }
            else dfs(i,cnt+1,p,u);
        }
    }
}

inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= n; i++) father[i] = i,e[i][i] = 2;
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        e[u][v] = e[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ++tot;
            t1 = i;t2 = 0;
            dfs(i,1,tot,0);
            // if (siz[i] % 2 == 1) {
            //     puts("No");
            //     exit(0);
            // }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j =i+1; j <= n; j++) {
            if (e[i][j] == 1) {
                if (siz[bel[i]] == 1 || siz[bel[j]] == 1) continue;
                int p = find(i),q = find(j);
                if (p != q) {
                    puts("No");
                    return 0;
                }else{
                    
                    father[p] = q;
                }
            }
        }
    }
    tot = 0;
    for (int i = 1; i <= n; i++) {
        if (siz[bel[i]] == 1) {
            s[i] = 'b';
        }else{
            int p = find(i);
            if (!ch[p]) {
                if (tot == 0) {
                    ch[p] = 1;
                    s[i] = 'a';
                    ++tot;
                }else if (tot == 1) {
                    ch[p] = 2;
                    s[i] = 'c';
                    ++tot;
                }else{
                    assert(0);
                }
            }else if(ch[p] == 1) {
                s[i] = 'a';
            }else{
                s[i] = 'c';
            }
        }
        
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) putchar(s[i]);
    return 0;
}