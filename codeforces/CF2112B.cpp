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
        x=(x<<3)+(x<<1)+(48^ch);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 1e3+30;
int T;
int n,a[maxn];bool is[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i],is[i] = false;
        bool f = false;
        for (int i = 1; i < n; i++) if (abs(a[i]-a[i+1])<=1) f = true;
        if (f) {
            puts("0");continue;
        }
        for (int i = 2; i < n; i++) {
            if (a[i-1]>a[i]&&a[i]<a[i+1]) {
                f = true;break;
            }else if(a[i-1]<a[i]&&a[i]>a[i+1]) {
                f = true;break;
            }
        }
        if (f) puts("1");
        else puts("-1");
    }

    return 0;
}