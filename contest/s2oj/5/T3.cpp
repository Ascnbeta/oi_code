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
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int T,C;
int n,m;
int s[100005],t[100005];
int ind[1000003],oud[1000004];
map<pair<int,int>,int> mp;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(T),read(C);
    while (T--) {
        int cnt = 0;vector<int> ans;
        read(n),read(m);
        for (int i = 1; i <= n; i++) read(s[i]);
        for (int i = 1; i <= m; i++) read(t[i]);
        for (int i = 1; i <= n-m+1; i++) {
            for (int j = 1; j <= C; j++) ind[j] = oud[j] = 0;
            mp.clear();
            int tmp = i;
            for (int j = 1; j <= m; j++,++tmp) {
                if (mp.find({s[tmp],t[j]}) == mp.end()) {
                    ++oud[s[tmp]],++ind[t[j]];
                    mp[{s[tmp],t[j]}] = 1;
                }
            }
            bool f = true;
            for (int j = 1; j <= C; j++) {
                if (ind[j] >= 2 || oud[j] >= 2) {
                    f = false;break;
                }
            }
            if (f) ++cnt,ans.push_back(i);
        }
        write(cnt);putchar('\n');
        for (int i : ans) write(i),putchar(' ');
        putchar('\n');
    }
    return 0;
}//?pts