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
int T;
int n;
int father[1<<20],rk[1<<20];
inline int find(int x) {
    int t = x;
    while (x != father[x]) x = father[x];
    int w;
    while (t != father[t]) w = father[t],father[t] = x,t = w;
    return x;
}
inline void merge(int x,int y) {
    int p = find(x),q = find(y);
    if (p == q) return;
    father[q] = p;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < (1<<n); i++) father[i] = i;
        string s;cin >> s;
        s = '0' + s;
        for (int i = 0; i < (1<<n); i++) {
            if (s[i]=='1') continue;
            for (int j = 1; j <= n; j++) {
                if ((i>>(j-1))&1) continue;
                int tmp = i|(1<<(j-1));
                if (s[tmp]=='1') continue;
                father[tmp] = min(father[tmp],father[i]);
            }
        }
        if (father[(1<<n)-1] == 0) puts("Yes");
        else puts("No");
    }
    return 0;
}