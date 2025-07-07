#include <bits/stdc++.h>
using namespace std;
string s;
deque<char> st;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (!st.empty()) {
            if (st.back() == s[i]) st.pop_back();
            else st.push_back(s[i]);
        }else{
            st.push_back(s[i]);
        }
    }
    while (!st.empty()) cout << st.front(),st.pop_front();
    return 0;
}