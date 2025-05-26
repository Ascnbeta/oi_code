#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll cnt = 0,tmp = 0;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int i = n; i >= 1; i--) {
        ++cnt;
        ll p = tmp%10;
        cnt += (s[i]-'0'-p+20)%10;
        tmp = (tmp+(s[i]-'0'-p+20)%10)%10;
    }
    cout << cnt << '\n';
    return 0;
}   