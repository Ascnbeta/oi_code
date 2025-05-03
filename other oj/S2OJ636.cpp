#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5+20;
int n,m,k;
struct obj{
    int p,q;
}a[maxn];
int sum = 0;
bool cmp1(const obj &x,const obj &y) {
    return x.q < y.q;
}
bool cmp2(const obj &x,const obj &y) {
    return x.p < y.p;
}
priority_queue<int,vector<int>,greater<int>> q;
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/wt.out","w",stdout);
#endif
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p >> a[i].q;
    }
    sort(a+1,a+n+1,cmp1);
    int cnt = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i].q;
        q.push(a[i].p-a[i].q);
        ++cnt;
        if (sum > m) {
            cout << cnt-1 << '\n';
            return 0;
        }
    }
    if (k == n)
    sort(a+k+1,a+n+1,cmp2);
    for (int i = k+1; i <= n; i++) {
        int tmp = q.top();
        if (a[i].q + tmp < a[i].p) {
            q.pop();
            q.push(a[i].p-a[i].q);
            sum += a[i].q + tmp;
            ++cnt;
        }else{
            sum += a[i].p;
            ++cnt;
        }
        if (sum > m) {
            cout << cnt-1 << '\n';
        }
    }
    return 0;
}
/*
8 1 24
6 3
9 8
9 6
13 2
14 12
5 1
12 4
9 7
*/