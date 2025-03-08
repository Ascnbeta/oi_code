#include <bits/stdc++.h>
#define int long long
using namespace std;
struct num{
    int a[5004];
    int len;
    num(){
        len = 0;
        memset(a,0,sizeof(a));
    }
}n,m;
num operator * (num &x, int &y) {
    num ret;
    if (y == 0 || (x.len == 1 && x.a[1] == 0)) {
        ret.len = 1;
        ret.a[1] = 0;
        return ret;
    }
    ret.len = x.len;
    for (int i = 1; i <= ret.len; i++) {
        ret.a[i] += x.a[i] * y;
        ret.a[i+1] += ret.a[i] / 10;
        ret.a[i] %= 10;
    }
    while (ret.a[ret.len+1]) {
        ++ret.len;
        ret.a[ret.len+1] += ret.a[ret.len] / 10;
        ret.a[ret.len] %= 10;
    }
    return ret;
}
num read() {
    num ret;
    string s;
    cin >> s;
    for (int i = s.size()-1; i >= 0; i--) {
        ret.a[s.size()-i] = s[i] - '0';
    }
    ret.len = s.size();
    return ret;
}
bool operator > (const num &x,const num &y) {
    if (x.len == y.len) {
        for (int i = x.len; i >= 1; i--) {
            if (x.a[i] > y.a[i]) {
                return true;
            }else if (x.a[i] < y.a[i]) {
                return false;
            }else{
                continue;
            }
        }
    }
    return x.len > y.len;
}
signed main () {
    n = read(), m = read();
    int l = 0, r = 6227020800;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (m * mid > n) {
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << l - 1 << '\n';
    return 0;
}