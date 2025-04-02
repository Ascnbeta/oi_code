#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int n;
int a[maxn<<1];
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    int i = 1,j = 2;
    while (i <= n && j <= n) {
        int k = 0;
        for (;k < n && a[i+k] == a[j+k]; k++);
        if (k == n) break;
        if (a[i+k] > a[j+k]) {
            i = i + k + 1;
            if (i == j) ++i;
        }else{
            j = j + k + 1;
            if (i == j) ++j;
        }
    }
    int ans = min(i,j);
    for (int i = 0; i < n; i++) {
        cout << a[ans+i] << ' ';
    }
    cout << '\n';
    return 0;
}