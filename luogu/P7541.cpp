#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
bool is_L;
int a[13],tot,tott,ans,b[13];
bool check_b(char ch) {
    return ch != '_' && (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}
bool check_f(char ch) {
    return ch != '_' && !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}
bool put_b(int pos) {
    int cnt1 = 0,cnt2 = 0;
    for (int i = pos; i < s.size() && i <= pos + 2; i++) {
        if (check_b(s[i])) ++cnt1;
    }
    if (cnt1 == 2) return false;
    for (int i = pos; i >= 0 && i >= pos - 2; i--) {
        if (check_b(s[i])) ++cnt2;
    }
    if (cnt2 == 2) return false;
    if (cnt1 == 1 && cnt2 == 1) {
        if (check_b(s[pos-1]) && check_b(s[pos+1])) return false;
    }
    return true;
}
bool put_f(int pos) {
    int cnt1 = 0,cnt2 = 0;
    for (int i = pos; i < s.size() && i <= pos + 2; i++) {
        if (check_f(s[i])) ++cnt1;
    }
    if (cnt1 == 2) return false;
    for (int i = pos; i >= 0 && i >= pos - 2; i--) {
        if (check_f(s[i])) ++cnt2;
    }
    if (cnt2 == 2) return false;
    if (cnt1 == 1 && cnt2 == 1) {
        if (check_f(s[pos-1]) && check_f(s[pos+1])) return false;
    }
    return true;
}
int dfs(int x,bool y) {
    if (x == tott + 1 && y == true) {
        return 1;
    }else if (x == tott + 1 && y == false) {
        return 0;
    }
    int tmp = 0;
    if (put_b(b[x])) {
        s[b[x]] = 'A';
        tmp += 5 * dfs(x+1,y);
        s[b[x]] = '_';
    }
    if (put_f(b[x])) {
        s[b[x]] = 'B';
        tmp += 20 * dfs(x+1,y);
        s[b[x]] = '_';
    }
    if (put_f(b[x])) {
        s[b[x]] = 'L';
        tmp += dfs(x+1,true);
        s[b[x]] = '_';
    }
    return tmp;
}
signed main () {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') {
            a[++tot] = i;
        }else if (s[i] == 'L') {
            is_L = true;
        }
    }
    tott = tot;
    for (int i = 1; i <= tot; i++) b[i] = a[i];
    ans = dfs(1,is_L);
    cout << ans << endl;
    return 0;
}