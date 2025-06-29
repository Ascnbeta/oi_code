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
int T;
int a,x,y;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T);
    while(T--) {
        read(a),read(x),read(y);
        if (x > y) swap(x,y);
        if (a < x && a < y) puts("yes");
        else if (a > x && a > y) puts("yes");
        else puts("no");
    }
    return 0;
}