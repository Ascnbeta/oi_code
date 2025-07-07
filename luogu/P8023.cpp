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
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
const int maxn = 2e5+5;
const ll mod = 2327265401;
const ll base = 131;
int n,m;
int a[maxn],b[maxn];
vector<int> ans;
ll h1[maxn],h2[maxn];
ll bpow[maxn];
inline bool check(int len,int i,int j) {
    return h1[i+len-1]-h1[i-1]==h2[j+len-1]-h2[j-1];
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    bpow[0] = 1;
    for (int i = 1; i <= 2e5; i++) bpow[i] = bpow[i-1]*base%mod;
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]),h1[i]=(h1[i-1]+1ll*a[i]*bpow[i-1]%mod)%mod;
    read(m);
    for (int i = 1; i <= m; i++) read(b[i]),h2[i]=(h2[i-1]+1ll*b[i]*bpow[i-1]%mod)%mod;
    if (n < m) {
        for (int i = n+1; i <= m; i++) a[i] = 1002,h1[i]=(h1[i-1]+1ll*a[i]*bpow[i-1]%mod)%mod;
        // n = m;
    }else if(n > m) {
        for (int i = m+1; i <= n; i++) b[i] = 1002,h2[i]=(h2[i-1]+1ll*b[i]*bpow[i-1]%mod)%mod;
        // m = n;
    }
    int i = 1,j = 1;
    for (int i = 1; i <= n; i++) cerr << h1[i] << ' ';
    cerr << '\n';
    for (int i = 1; i <= m; i++) cerr << h2[i] << ' ';
    cerr << '\n';
    for (;i <= n && j <= m;) {
        if (a[i] < b[j]) {
            ans.push_back(a[i]);
            ++i;
        }else if(a[i] > b[j]) {
            ans.push_back(b[j]);
            ++j;
        }else{
            int l = 1,r = min(n-i+1,m-j+1),len = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (check(mid,i,j)) {
                    len = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            if (i+len-1 < n && j+len-1 < m) {
                if (a[i+len] < b[j+len]) {
                    ans.push_back(a[i]);
                    ++i;
                }else{
                    ans.push_back(b[j]);
                    ++j;
                }
            }else{
                if (i+len-1 == n) {
                    ans.push_back(b[j]);
                    ++j;
                }else{
                    ans.push_back(a[i]);
                    ++i;
                }
            }
        }
    }
    while (i <= n) ans.push_back(a[i]),++i;
    while (j <= m) ans.push_back(b[j]),++j;
    for (int &tmp : ans) if(tmp!=1002)write(tmp),putchar(' ');
    return 0;
}