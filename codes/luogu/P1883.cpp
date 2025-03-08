#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int T,n,a[10004],b[10004],c[10004];
double solve(double x,int p) {
    return a[p]*x*x+b[p]*x+c[p];
}
double f(double x) {
    double tmp = solve(x,1);
    for (int i = 2; i <= n; i++) tmp = max(tmp,solve(x,i));
    return tmp;
}
int main () {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
        double l = 0.0,r = 1000.0;
        while (r - l > eps) {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            if (f(m1) < f(m2)) {
                r = m2;
            }else{
                l = m1;
            }
        }
        cout << fixed << setprecision(4) << f(l) << '\n';
    }
    return 0;
}