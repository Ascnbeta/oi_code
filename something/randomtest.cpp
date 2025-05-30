#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(random_device{}());
inline int randrange(int l,int r) {
    return rnd()%(r-l+1)+l;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    int n = 100000,m = 400000;
    cout << n << ' ' << m << '\n';
    for (int i = 2; i <= n; i++) {//从2开始！
        cout << i << ' ' << rnd()%(i-1)+1 << '\n';
    }
    for (int i = 100000; i <= m; i++) {
        cout << rnd()%n+1 << ' ' << rnd()%n+1 << '\n';
    }
    return 0;
}  