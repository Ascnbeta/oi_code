#include <bits/stdc++.h>
using namespace std;
int x;
inline bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main () {
    cin >> x;
    for (int i = x; i <= 200000; i++) {
        if (check(i)) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}