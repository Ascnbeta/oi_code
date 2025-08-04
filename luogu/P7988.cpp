#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
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
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar(' ');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 2e5+5;
int n,a[maxn],w[maxn],st[maxn],top;
int ls[maxn],rs[maxn],root;
void dfs(int u,int cnt,int lst) {
    if (ls[u]) {
        dfs(ls[u],cnt,0);
    }else{
        write(cnt),putchar('\n');
    }
    if (rs[u]) {
        if (lst == 0) {
            dfs(rs[u],cnt+1,1);
        }else{
            dfs(rs[u],cnt,1);
        }
    }else{
        write(cnt+(lst==0)),putchar('\n');
    }
}
int main () {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]),w[a[i]] = i;
    root = a[1];
    for (int i = 1; i <= n; i++) {
        int tmp = top;
        while (tmp&&w[st[tmp]]>w[i]) --tmp;
        if (tmp) rs[st[tmp]] = i;
        if (tmp < top) ls[i] = st[tmp+1];
        st[++tmp] = i;
        top = tmp;
    }
    dfs(root,0,-1);
    return 0;
}