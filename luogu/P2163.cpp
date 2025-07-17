#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n,m;
int t[10000005];
inline int lowbit(int x) {
    return x & (-x);
}
inline void modify(int p,int x) {
    while (p <= 10000000) {
        t[p] += x;
        p += lowbit(p);
    }
}
inline int query(int p) {
    int ret = 0;
    while (p > 0) {
        ret += t[p];
        p -= lowbit(p);
    }
    return ret;
}
struct node{
    int tp,x,y,id;
    bool operator < (const node &t) const{
        if (x == t.x) return tp < t.tp;
        return x < t.x;
    }
}p[maxn*5];int tot,ans[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        ++p[i].x,++p[i].y;
        p[i].tp = 1;
    }
    tot = n;
    for (int i = 1; i <= m; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        ++a,++b,++c,++d;
        p[++tot] = {2,a-1,b-1,i};
        p[++tot] = {3,a-1,d,i};
        p[++tot] = {3,c,b-1,i};
        p[++tot] = {2,c,d,i};
    }
    sort(p+1,p+tot+1);
    for (int i = 1; i <= tot; i++) {
        if (p[i].tp == 1) {
            modify(p[i].y,1);
        }else if(p[i].tp == 2) {
            ans[p[i].id] += query(p[i].y);
        }else if (p[i].tp == 3) {
            ans[p[i].id] -= query(p[i].y);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}