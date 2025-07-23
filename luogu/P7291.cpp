#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read()
{
    char c=getchar();int x=0;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    return x;
}
const int maxn = 1e7+7;
int n;
int k[maxn];
int st[maxn],top;
ll ans;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    n = read();
    for (int i = 1; i <= n; i++) k[i] = read(),ans = max(ans,1ll*k[i]*i);
    for (int i = 1; i <= n; i++) {
        while (top&&k[st[top]]<k[i]) ans = max(ans,1ll*k[st[top]]*(st[top]+i)),--top;
        if (top) {
            ans = max(ans,1ll*k[i]*(st[top]+i));
        }
        st[++top] = i;
    }
    printf("%lld",ans);
    return 0;
}