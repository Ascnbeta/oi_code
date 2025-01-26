#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
double maxx;
struct cf{
    int v,c;
    double w;
}c[204];
int n,m;
bool cmp(cf x,cf y) {
    return x.w > y.w;
}
bool check (double x) {
    for (int i = 1; i <= n ; i++) {
        c[i].w = c[i].v - x * c[i].c;
    }
    sort(c+1,c+n+1,cmp);
    double tmp = 0;
    for (int i = 1; i <= m; i++) {
        tmp += c[i].w;
    }
    if (tmp >= 0) return true;
    return false;
}
int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].v;
    }
    for (int i = 1; i <= n ;i++) {
        cin >> c[i].c;
        maxx = max(1.0*c[i].v/c[i].c,maxx);
    }
    double l = 0,r = maxx;
    while (r - l > eps) {
        double mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << fixed << setprecision(3) << l << endl;
    return 0;
}