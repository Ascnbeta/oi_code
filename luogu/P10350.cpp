#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.3e6+30;
int n,q;
inline void read(int &v) {
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    v=x*f;
    return;
}
inline void write(int x){
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int father[maxn],rk[maxn],siz[maxn];
bool f[maxn];
int idx[maxn];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    if (rk[x] > rk[y]) {
        father[y] = x;
        rk[x] = max(rk[x],rk[y]+1);
        siz[x] += siz[y];
        f[x] |= f[y];
    }else{
        father[x] = y;
        rk[y] = max(rk[y],rk[x]+1);
        siz[y] += siz[x];
        f[y] |= f[x];
    }
}
int tot;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n),read(q);
    for (int i = 1; i <= n+q; i++) father[i] = i;
    for (int i = 1; i <= n; i++) idx[i] = i,siz[i] = 1;
    tot = n;
    while (q--) {
        char op = getchar();
        if (op == '?') {
            int a;
            read(a);
            int x = find(idx[a]);
            if (siz[x] == 1) putchar('0'+f[x]);
            else putchar(f[x]?'1':'?');
        }else if(op == '+') {
            int a,b;
            read(a),read(b);
            a = idx[a],b = idx[b];
            int x = find(a),y = find(b);
            if (x == y) {
                f[x] = f[y] = true;
            }else{
                merge(x,y);
            }
        }else{
            int a;
            read(a);
            int x = find(idx[a]);siz[x]--;
            idx[a] = ++tot; siz[tot] = 1;
        }   
    }
    return 0;
}