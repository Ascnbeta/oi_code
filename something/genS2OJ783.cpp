#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
mt19937 r(GetTickCount());
int main () {
    freopen("D:/codes/exe/a.in","w",stdout);
    int n = 1,m = 100000,tot = 50000;
    cout << n << ' ' << m << endl;
    const int line = 250;
    for (int i = 0; i < 200; i++) {
        int j = i*line+1;
        for (; j < (i+1)*line; j++) {
            cout << j << ' ' << j+1 << ' ' << r()%14500 << endl;
        }
    }
    // int cnt = 99550;
    for (int i = 0; i < 199; i++) {
        int j = i*line+1;
        for (; j <= (i+1)*line; j++) {
            cout << j << ' ' << j+line << ' ' << 0 << endl;
            // if (j != (i+1)*line && cnt <= m) cout << j << ' ' << j+line+1 << ' ' << r()%1450 << '\n',++cnt;
        }
    }
    
    for (int i = 99551; i <= 100000; i++) {
        cout << r()%300+1 << ' ' << r()%300+40000 << ' ' << 14800 << endl;
    }
    // for (int i = 1; i < tot; i++) {
    //     cout << i << ' ' << i+1 << ' ' << 15000 << '\n';
    // }
    // for (int i = tot; i <= m; i++) {
    //     int t = r()%tot+1;
    //     cout << t << ' ' << t << ' ' << 15000 << '\n';
    // }
    cout << tot << ' ';
    for (int i = 1; i < tot; i++) cout << i << ' ';
    cout << tot << endl;
    cout << 100 << endl;
    cout << 1 << ' ' << tot <<endl;
    return 0;
}