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
    x*=f;
}
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
string s;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int cnt = 0,a[3];
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.') continue;
        if (s[i] == '#') {
            a[cnt] = i;
            cnt = (cnt+1)%2;
            if (cnt == 0) {
                cout << a[0] << ',' << a[1] << '\n';
            }
        }
    }

    return 0;
}