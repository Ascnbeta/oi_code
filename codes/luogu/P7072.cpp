#include <bits/stdc++.h>
using namespace std;
int n,w;
int a[200005],t[604];
int main () {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        t[x]++;
        if (i == 1) {
            cout << x << ' ';
        }else{
            int m = w * i / 100;
            if (m < 1) m = 1;
            for (int j = 600; j >= 0; j--) {
                m -= t[j];
                if (m <= 0) {
                    cout << j << ' ';
                    break;
                }
            }
        }
    }
    return 0;
}