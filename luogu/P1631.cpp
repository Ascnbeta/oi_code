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
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 1e5+5;
int n,a[maxn],b[maxn];
struct node{
    int i,j;
    bool operator < (const node &y) const{
        return a[i]+b[j] > a[y.i]+b[y.j];
    }
};
priority_queue<node> q;
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    q.push({1,1});
    int n1 = n;
    while (n1--) {
        write(a[q.top().i]+b[q.top().j]),putchar(' ');
        int p = q.top().i,Q = q.top().j;
        q.pop();
        if (p+1 <= n) q.push({p+1,Q});
        if (Q+1 <= n) q.push({p,Q+1});
    }
    return 0;
}