#include <bits/stdc++.h>
#define ll long long
using namespace std;
double a,b;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> a >> b;
    double tmp = a/b;
    if (tmp-(int)tmp < 0.5) printf("%d",(int)tmp);
    else printf("%d",(int)tmp+1);
    return 0;
}