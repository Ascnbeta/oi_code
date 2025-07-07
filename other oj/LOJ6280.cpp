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
inline void write (T x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar('0'+x%10);
}
const int maxn = 5e4+5;
const ll B = 210;
int n;ll a[maxn],bel[maxn],sum[610],tag[610];
inline void add(int l,int r,ll v) {
    int lpos = bel[l],rpos = bel[r];
    if (lpos == rpos) {
        for (int i = l; i <= r; i++) {
            a[i] += v;
            sum[lpos] += v;
        }
    }else{
        for (int i = lpos+1; i <= rpos-1; i++) {
            tag[i] += v;
            sum[i] += B*v;
        }
        for (int i = l; bel[i] == lpos; i++) {
            a[i] += v;
            sum[lpos] += v;
        }
        for (int i = r; bel[i] == rpos; i--) {
            a[i] += v;
            sum[rpos] += v;
        }
    }
}
inline ll query(int l,int r,ll mod) {
    ++mod;
    int lpos = bel[l],rpos = bel[r];ll ret = 0;
    if (lpos == rpos) {
        for (int i = l; i <= r; i++) {
            ret = (ret + a[i] + tag[lpos]) % mod;
        }
        return ret;
    }else{
        for (int i = lpos+1; i <= rpos-1; i++) {
            ret = (ret + sum[i]) % mod;
        }
        for (int i = l; bel[i] == lpos; i++) {
            ret = (ret + a[i] + tag[lpos]) % mod;
        }
        for (int i = r; bel[i] == rpos; i--) {
            ret = (ret + a[i] + tag[rpos]) % mod;
        }
        return ret;
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        bel[i] = (i-1)/B+1;
        sum[bel[i]] += a[i];
    }
    for (int i = 1; i <= n; i++) {
        int op,l,r,c;
        read(op),read(l),read(r),read(c);
        if (op == 0) add(l,r,c);
        else write(query(l,r,c)),putchar('\n');
    }
    return 0;
}