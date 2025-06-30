#include <bits/stdc++.h>
using namespace std;
int t;
inline void solve() {
    int n;
    cin >> n;
    cout << "mul 9" << endl;
    int x;
    cin >> x;
    cout << "digit" << endl;
    cin >> x;
    cout << "digit" << endl;
    cin >> x;
    cout << "add " << n-9 << endl;
    cin >> x;
    cout << "!" << endl;
    cin >> x;
    assert(x!=-1);
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}