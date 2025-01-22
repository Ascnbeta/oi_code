#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ans;
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    auto x = unique(a+1,a+n+1);
    cout << max(*(x-3),(*(x-1)) % (*(x-2))) << endl;
    return 0;
}