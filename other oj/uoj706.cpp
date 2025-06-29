#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 1e6+30;
int n;int a[maxn];
long double kahanSum(vector<long double> &nums)
{
    long double sum = 0, c = 0;
    for (long double x : nums)
    {
        long double y = x + c, t = sum + y;
        c = y - (t - sum);
        sum = t;
    }
    return sum;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    vector<long double> t;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        t.push_back((long double)((long double)1e6-a[i])/((long double)1e6*n-a[i]));
    }
    long double res = kahanSum(t);
    cout << fixed << setprecision(11) << (n-res)/(1-res)/n << '\n';
    return 0;
}