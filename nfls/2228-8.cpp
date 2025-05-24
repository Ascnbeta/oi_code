#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+30;
const int mod = 998244353;
int n;
int a[maxn];
inline void read(int &x) {
    x=0;
    int f=1;char ch=getchar();
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
int t[maxn],f[maxn];
inline int lowbit(int x) {return x&-x;}
inline void modify(int p,int v) {
    while (p <= n) {
        t[p] = max(t[p],v);
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret = max(ret,t[p]);
        p -= lowbit(p);
    }
    return ret;
}
inline ll binpow(ll base,int b) {
    ll ret = 1;
    while (b){
        if(b&1) ret=ret*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return ret;
}
int len = 0;
stack<int> s;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    if (n==1) {
        puts("2");
        return 0;
    }
    for (int i = 1; i <= n; i++) read(a[i]);
    modify(a[n],1);
    f[n] = 1;len = 1;
    for (int i = n-1; i >= 1; i--) {
        f[i] = query(a[i])+1;
        len = max(len,f[i]);
        modify(a[i],f[i]);
    }
    // printf("%d\n",len);
    if (len > 2) {
        puts("0");
        return 0;
    }else if(len == 1) {
        printf("%lld",binpow(2,n));
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        if (s.empty()) s.push(a[i]);
        else{
            if (a[i]<s.top()) s.push(a[i]);
            else {
                int t = s.top();
                while (!s.empty() && a[i]>s.top()) {
                    s.pop();
                }
                s.push(t);
            }
        }
    }
    printf("%lld",binpow(2,s.size()));
    return 0;
}