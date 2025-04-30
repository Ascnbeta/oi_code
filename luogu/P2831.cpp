#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxn = 20;
const double eps = 1e-6;
int T;
int n,m;
double x[maxn],y[maxn];
vector<int> l;
inline pair<double,double> calc(int p,int q) {
    double x1 = x[p],x2 = x[q],y1 = y[p],y2 = y[q];
    if (fabs(y1/x1-y2/x2)<eps) return {0,0};
    double b = (y2-(y1*x2*x2)/(x1*x1))/(x2-x2*x2/x1);
    double a = (y1-x1*b)/(x1*x1);
    return {a,b};
}
int f[1<<maxn];
inline void print(int x) {
    stack<int> s;
    while (x) {
        s.push(x%2);
        x /= 2;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> T;
    while (T--) {
        cin >> n >> m;
        l.clear();
        for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) { 
                pair<double,double> t = calc(i,j);
                // cout << i << ' ' << j << ' ' << t.fi << ' ' << t.se << '\n';
                if (t == (pair<double,double>){0.0,0.0}) continue;
                if (t.fi >= 0) continue;
                int tmp = (1<<(i-1))|(1<<(j-1));
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) continue;
                    if (fabs(t.fi*x[k]*x[k]+t.se*x[k]-y[k]) < eps) tmp |= (1<<(k-1));
                }
                // print(tmp);
                l.push_back(tmp);
            }
        }
        for (int i = 0; i < (1<<n); i++) f[i] = 0x3f3f3f3f;
        f[0] = 0;
        for (int i = 0; i < (1<<n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1<<j)) == 0) {
                    f[i|(1<<j)] = min(f[i|(1<<j)],f[i]+1);
                }
            }
            for (int j = 0; j < (int)l.size(); j++) {
                // if (!((i^l[j])&l[j])) {
                    f[i|l[j]] = min(f[i|l[j]],f[i]+1);
                // }
            }
        }
        // for (int i = 0; i < (1<<n); i++) {
        //     print(i);
        //     cout << f[i] << '\n';
        // }
        cout << f[(1<<n)-1] << '\n';
    }
    return 0;
}