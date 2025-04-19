#include <bits/stdc++.h>
using namespace std;
const int maxn = 2.5e4+23;
int n;
struct ship{
    int u,v;
    bool operator < (const ship &y) const{
        if (u < v) {
            if (y.u < y.v) return u < y.u;
            return true;
        }else{
            if (y.u < y.v) return false;
            return v > y.v;
        }   
    }
}s[maxn];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i].u >> s[i].v;
    sort(s+1,s+n+1);
    int t0 = 0,t1 = 0; 
    for (int i = 1; i <= n; i++) {
        int tmp1 = t0 + s[i].u;
        t0 = tmp1;
        if (tmp1 >= t1) t1 = tmp1+s[i].v;
        else t1 += s[i].v;
    }
    cout << t1 << '\n';
    return 0;
}