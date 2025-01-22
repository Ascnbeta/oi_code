#include <bits/stdc++.h>
using namespace std;
bool f[20][20];
int n,ans = 0;
int solve(char x){
    if (x == 'A') return 1;
    if (x == 'T') return 10;
    if (x == 'J') return 11;
    if (x == 'Q') return 12;
    if (x == 'K') return 13;
    return (int)(x - '0');
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int tp,v;
        if (s[0] == 'D') tp = 1;
        if (s[0] == 'H') tp = 2;
        if (s[0] == 'C') tp = 3;
        if (s[0] == 'S') tp = 4;
        v = solve(s[1]);
        f[tp][v] = true;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (!f[i][j]) ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}