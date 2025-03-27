#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+30;
int n;
string s,ans = " ";
int ord[maxn],tot,pt;
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            ++pt;
            if (s[i] == '*' || s[i] == '/') ord[pt] = ++tot;
        }
    }
    pt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            ++pt;
            if (s[i] == '+' || s[i] == '-') ord[pt] = ++tot;
        }
    }
    pt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            ++pt;
            cout << s[i] << '[' << to_string(ord[pt]) << ']';
        }else{
            cout << s[i];
        }
    }
    return 0;
}