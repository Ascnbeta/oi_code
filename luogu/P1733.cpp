#include <bits/stdc++.h>
using namespace std;

int main () {
    int l = 1,r = (int)1e9;
    while (1) {
        int mid = (l + r) >> 1;
        cout << mid << endl;
        int ret;
        cin >> ret;
        if (ret == 0) {
            return 0;
        }else if (ret == 1) {
            r = mid - 1;
        }else if (ret == -1) {
            l = mid + 1;
        }
    }
    return 0;
}