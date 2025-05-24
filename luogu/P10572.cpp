#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+20;
int n,m,q;
char s[maxn];
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
vector<int> e[maxn];
int fa1[maxn],rk1[maxn],fa2[maxn],rk2[maxn];
inline int find1(int x) {
    int t = x;
    while (x != fa1[x]) x = fa1[x];
    int w;
    while (t != fa1[t]) w = fa1[t],fa1[t] = x,t = w;
    return x;
}
inline int find2(int x) {
    int t = x;
    while (x != fa2[x]) x = fa2[x];
    int w;
    while (t != fa2[t]) w = fa2[t],fa2[t] = x,t = w;
    return x;
}
bool tag[maxn],l[maxn],r[maxn];
inline void add(int u,int v) {
    if (s[u] != s[v]) {
        int p = find1(u),q = find1(v);
        if (p != q) {
            if (rk1[p] <= rk1[q]) {
                fa1[p]=q;
                rk1[q]=max(rk1[p]+1,rk1[q]);
            }else{
                fa1[q]=p;
                rk1[p]=max(rk1[q]+1,rk1[p]);
            }
        }
    }else tag[u]=tag[v]=true;
    int p = find2(u),q = find2(v);
    if (p != q) {
        if (rk2[p] <= rk2[q]) {
            fa2[p]=q;
            rk2[q]=max(rk2[p]+1,rk2[q]);
        }else{
            fa2[q]=p;
            rk2[p]=max(rk2[q]+1,rk2[p]);
        }
    }
    e[u].push_back(v);
    e[v].push_back(u);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(m),read(q);
    scanf("%s",s+1);
    for (int i = 1; i <= n; i++) fa1[i]=fa2[i]=i;
    for (int i = n+1; i <= 2*n; i++) s[i] = s[i-n],fa1[i]=fa2[i]=i;
    for (int i = 1; i <= m; i++) {
        int u,v;
        read(u),read(v);
        add(u,v+n),add(v,u+n);
    }
    for (int i = 1; i <= 2*n; i++) {
        int t = find1(i);
        for (auto v : e[i]) {
            l[t] |= tag[v]&&s[v]=='(';
            r[t] |= tag[v]&&s[v]==')';
        }
    }
    while (q--) {
        int u,v;
        read(u),read(v);
        if (s[u]==')'||s[v]=='(') putchar('0');
        else if (find2(u)!=find2(v+n)) putchar('0');
        else if (l[find1(u)]&&r[find1(v+n)]) putchar('1');
        else if (find1(u)==find1(v+n)) putchar('1');
        else putchar('0');
    }
    return 0;
}