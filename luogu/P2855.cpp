#include <bits/stdc++.h>
using namespace std;
int L,n,m;
int a[50004];
bool check(int x) {
    int tmp = 0,t1 = 0;
    for (int i = 1,j = 0; i <= n + 1; i++){
        t1 = i;
        if (a[i] - a[j] < x) {
            tmp++;
        }else{
            j = t1;
        }
    }
    if (tmp > m) return false;
    return true;
}
int main () {
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    a[n+1] = L;
    int l = 1,r = L;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << l - 1 << endl;
    return 0;
}