#include <bits/stdc++.h>
typedef long long ll;
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
    x *= f;
}
const int maxn = 3e5+40;
int n;ll p[maxn];
priority_queue<ll> q;
ll ans;
int main() {
#ifdef LOCAL
    freopen("E:/OI/exe/a.in","r",stdin);
    freopen("E:/OI/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) read(p[i]);
    for (int i = 1; i <= n; i++) {
        q.push(-p[i]);
        if (q.top()+p[i] < 0) continue;
        ans += p[i]+q.top();q.pop();q.push(-p[i]);
    }
    printf("%lld",ans);
    return 0;
}