#include <bits/stdc++.h>
#include <windows.h>
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
mt19937 r(GetTickCount());
int main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","w",stdout);
#endif
    cout << 499 << ' ' << 499 << '\n';
    for (int i = 1; i <= 499; i++) {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= 499; i++) {
        cout << r()%499+1 << ' ';
    }
    cout << '\n';
    return 0;
}