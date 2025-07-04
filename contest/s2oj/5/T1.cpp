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
        x=(x<<3ll)+(x<<1ll)+(ch^48);
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
int T;
ll m,k,h;
inline bool check(ll x) {
    if (x < m) return x >= h;
    else {
        ll t1 = (x-m)/(m-k);
        ll t2 = (x-m)%(m-k)+m;
        if (t2>=m) t2 = t2-m+k,++t1;
        return t1*m+t2 >= h;
    }
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    int st = clock();
    read(T);
    while (T--) {
        read(m),read(k),read(h);
        if (m >= h) write(h),putchar('\n');
        else if(m == k) write(m),putchar('\n');
        else {
            ll l = 0,r = h,ans = h;
            while (l <= r) {
                ll mid = (l + r) >> 1;
                if (check(mid)) {
                    ans = mid;
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            write(ans),putchar('\n');
        }
    }
    cerr << clock() - st << '\n';
    return 0;
}