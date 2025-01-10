#include <bits/stdc++.h>
using namespace std;
int T;
int x,y;
int main () {
    cin >> T;
    while (T--) {
        cin >> x >> y;
        if (x % 2 == 1) {
            if (y != 1) {
                cout << y << ' ' << 1 << endl;
            }else{
                cout << 1 << ' ' << y << endl;
            }
        }else{
            if (y == 1) {
                cout << y << ' ' << 1 << endl;
            }else{
                cout << 1 << ' ' << y << endl;
            }
        }
    }
    return 0;
}