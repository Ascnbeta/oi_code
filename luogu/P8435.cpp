#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 5e5+30;
int n,m;
vector<int> e[maxn];
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
int dfn[maxn],low[maxn],cnt;
bool f[maxn];
int vis[maxn],bcc;
vector<int> bc[maxn];
stack<int> st;
void tarjan(int u,int fa) {
    dfn[u]=low[u]=++cnt;
    st.push(u);
    int child = 0;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            ++child;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v] >= dfn[u]) {
                ++child;
                if (fa != 0 || child >= 2) f[u] = true;
                ++bcc;
                int tmp = 0;
                do {
                    tmp = st.top();
                    st.pop();
                    bc[bcc].push_back(tmp);
                }while (tmp != v);
                bc[bcc].push_back(u);
            }
        }else if (v != fa) {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (fa == 0 && child == 0) bc[++bcc].push_back(u);
}

inline void write(int x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    read(n),read(m);
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i,0);
        }
    }
    write(bcc);putchar('\n');
    for (int i = 1; i <= bcc; i++) {
        write(bc[i].size());putchar(' ');
        for (auto j : bc[i]) {
            write(j);putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}