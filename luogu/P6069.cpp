#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
int n;
long long m;
long long a[200005];
__int128 ah[200005],ap[200005];
bool check(int x) {
    long double tmp;
    for (int i = 1; i + x - 1 <= n; i++) {
        __int128 t2 = ap[i+x-1]-ap[i-1];
        __int128 t3 = ah[i+x-1]-ah[i-1];
        long double t1 = (ah[i+x-1]-ah[i-1])*1.0/x;
        tmp = t2 - 2 * t1 * t3 + x * t1 * t1;
        if (tmp <= m) return true;
    }
    return false;
}
int main () {
    freopen("1.in","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) {
        ah[i] = a[i] + ah[i-1];
        ap[i] = a[i] * a[i] + ap[i-1];
    }
    int l = 1,r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << n - l + 1 << '\n';
    return 0;
}