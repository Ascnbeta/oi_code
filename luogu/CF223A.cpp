#include <bits/stdc++.h>
using namespace std;
string s;
stack<int> st;
bool m[100005];
int l,r,ans,tot = 1;
struct zone{
    int l,r,cnt;
}z[100005];
int main () {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') st.push(i);
        else if (s[i] == ')') {
            if (!st.empty() && s[st.top()] == '(') {
                m[i] = m[st.top()] = true;
                st.pop();
            }else{
                while (!st.empty()) st.pop();
            }
        }else {
            if (!st.empty() && s[st.top()] == '[') {
                m[i] = m[st.top()] = true;
                st.pop();
            }else{
                while (!st.empty()) st.pop();
            }
        }
    }
    int tmp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (m[i]) {
            z[tot].l = i;
            int cnt = 0;
            for (int j = i; m[j]; j++) {
                if (s[j] == '[') {
                    ++cnt;
                }
                z[tot].r = j;
            }
            i += z[tot].r - z[tot].l;
            z[tot++].cnt = cnt;
        }
    }
    for (int i = 1; i < tot; i++) {
        if (z[i].cnt > ans) {
            ans = z[i].cnt;
            l = z[i].l;
            r = z[i].r;
        }
    }
    cout << ans << '\n';
    if (ans == 0) {
        cout << "";
        return 0;
    }
    for (int i = l; i <= r; i++) {
        cout << s[i];
    }
    return 0;
}