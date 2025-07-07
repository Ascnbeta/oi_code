#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
mt19937_64 r(GetTickCount());
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","w",stdout);
#endif
    cout << r()%1000000+1 << '\n';
    return 0;
}