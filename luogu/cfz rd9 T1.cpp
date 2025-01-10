#include <bits/stdc++.h>
using namespace std;
int T,n,m;
int main () {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (m % n == 0) cout << "Yes" << endl;
        else if (m % n == n - 1) cout << "Yes" << endl;
        else if (m / n != 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}