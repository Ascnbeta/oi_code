#include <bits/stdc++.h>
using namespace std;
int n,sum;
inline void read(int &x) {
    int f=1;
    char ch = getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch = getchar();
    }
    while (ch>='0'&&ch<='9') {
        x = (x<<3)+(x<<1)+(ch^48);
        ch = getchar();
    }
    x*=f;
}
inline void write(int x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    int a;
    while (n--) a=0,read(a),sum+=a;
    write(sum);
    return 0;   
}