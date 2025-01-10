#include <bits/stdc++.h>
using namespace std;
int n,m;
string a,b,c,d,ans = "";
struct op{
    int l,r;
}o[200005];
int cf[200005];
bool cmp(op x,op y) {
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}
int main () {
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> a >> b;
    c = a; d = b;
    for (int i = 1; i <= m; i++) {
        cin >> o[i].l >> o[i].r;
        o[i].l--;
        o[i].r--;
    }
    if (n <= 20 && m <= 20) {
        int tmp = pow(2,m);
        for (int i = 0; i < tmp; i++) {
            int t = i;
            c = a, d = b;
            for (int j = 1; j <= m; j++, t >>= 1) {
                if (t&1) {
                    for (int k = o[j].l; k <= o[j].r; k++) {
                        swap(c[k],d[k]);
                    }
                }
            }
            if (c > ans) {
                ans = c;
            }
        }
        cout << ans << endl;
    }else{
        sort(o+1,o+m+1,cmp);
        for (int i = 1; i <= m; i++) {
            if (a[o[i].l] == '0') {
                cf[o[i].l] += 1;
                cf[o[i].r+1] -= 1;
            }
        }
        cout << a << endl;
    }
    return 0;
}