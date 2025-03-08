#include <bits/stdc++.h>
using namespace std;
int n;
string dfs(int x) {
    if (x == 1) {
        return "1 ";
    }
    string t;
    int u = x;
    while (u) {
        t += (char)(u%10+'0');
        u /= 10;
    }
    reverse(t.begin(),t.end());
    t += ' ';
    return dfs(x-1)+t+dfs(x-1);
}
int main () {
    cin >> n;
    string s = dfs(n);
    cout << s;
    return 0;
}