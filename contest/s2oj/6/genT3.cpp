#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
mt19937 r(GetTickCount());
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","w",stdout);
#endif
    cout << 100 << ' ' << r()%1000+9000 << ' ' << r()%1000+9000 << '\n';
    for (int i = 1; i <= 100000; i++) cout << r()%100+1 << ' ';
    return 0;
}