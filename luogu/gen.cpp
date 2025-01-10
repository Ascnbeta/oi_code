#include <bits/stdc++.h>
using namespace std;
mt19937 t(time(0));
int cr(int l,int r) {
    int ret = (int)((1.0 * t() / UINT_MAX) * (r - l + 1)) + l;
    return ret;
}
bool f[5000000];
struct node{
    int a,b;
}a[3003];
bool cmp(node x,node y) {
    return x.a < y.a;
}
int main () {
    int cnt = 2000;
    cout << 2000 << '\n';
    for (int i = 1; i <= cnt; i++) {
        int x = cr(-250000,205000);
        if (f[x+300000]) {--i;continue;}
        f[+300000] = true;
        int y = cr(1000,90000);
        a[i].a = x,a[i].b = y;
    }
    sort(a+1,a+cnt+1,cmp);
    for (int i = 1; i <= cnt; i++) {
        cout << a[i].a << ' ' << a[i].b << '\n';
    }
    cout << 2000 << '\n';
    while (cnt--) {
        int x = cr(-250000,205000);
        int y = cr(-250000,205000);
        if (x > y) swap(x,y);
        if (x == y) {
            ++cnt;
            continue;
        }
        cout << x << ' ' << y << '\n';
    }
    return 0;
}