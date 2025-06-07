#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+30;
const int maxm = 7e6+30;
queue<ll> q1,q2,q3;
int n,m;
ll q,u,v,t;
ll sum;
inline void read(int &x) {
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
inline void read(ll &x) {
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
inline void write(ll x) {
    if (x<0) putchar('-'),x=-x;
    if (x/10) write(x/10);
    putchar(x%10+'0');
}
int a[maxn];
vector<ll> ans;
int main () {
#ifdef LOCAL
    freopen("D:\\codes\\exe\\a.in","r",stdin);
    freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
    read(n),read(m),read(q),read(u),read(v),read(t);
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a+1,a+n+1,greater<int>());
    for (int i = 1; i <= n; i++) q1.push(a[i]);
    for (int i = 1; i <= m; i++) {
        ll x=-1e9,y=-1e9,z=-1e9;
        if (!q1.empty()) x=q1.front();
        if (!q2.empty()) y=q2.front();
        if (!q3.empty()) z=q3.front();
        ll tmp = max(x,max(y,z));
        if (tmp == x) q1.pop();
        else if (tmp == y) q2.pop();
        else q3.pop();
        if (i%t == 0) write(tmp+sum),putchar(' ');
        tmp += sum;
        ll t2 = (long double)1.0*u/v*tmp;
        ll t3 = tmp-t2;
        q2.push(t2-sum-q);
        q3.push(t3-sum-q);
        sum += q;
    }
    putchar('\n');
    while (!q1.empty()) ans.push_back(q1.front()+sum),q1.pop();
    while (!q2.empty()) ans.push_back(q2.front()+sum),q2.pop();
    while (!q3.empty()) ans.push_back(q3.front()+sum),q3.pop();
    sort(ans.begin(),ans.end(),greater<int>());
    for (int i = t; i <= n+m; i += t) {
        write(ans.at(i-1)),putchar(' ');
    }
    return 0;
}