#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
mt19937 r(GetTickCount());
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","w",stdout);
#endif
    cout << 4 << '\n';
    for (int i = 1; i <= 4; i++) cout << r()%9+1 << ' ';
    return 0;
}