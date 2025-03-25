#include <bits/stdc++.h>
using namespace std;
int T,k,cnt;
deque<char> q;
int b[29],used[29];
string s;
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while (T--) {
        q.clear();
        memset(b,0,sizeof(b));
        memset(used,0,sizeof(used));
        cin >> k >> s;
        int n = s.size();
        s = ' ' + s;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            b[s[i]-'a']++;
        }
        int tot = 0;
        for (int i = 0; i <= 25; i++) {
            if (b[i]) ++tot;
        }
        if (tot <= k) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            while (q.size() && q.back() > s[i]) {
                char lst = q.back();
                if (s[i] < lst) {
                    if (b[lst-'a'] != 0 || used[lst-'a'] >= 2) {
                        q.pop_back();
                        --used[lst-'a'];
                        continue; 
                    }else{
                        if (cnt < k) {
                            ++cnt;
                            q.pop_back();
                            --used[lst-'a'];
                            continue;
                        }else{
                            break;
                        }
                    }
                }
            }
            q.push_back(s[i]);
            ++used[s[i]-'a'];
            b[s[i]-'a']--;
        }
        string tmp = " ";
        n = q.size();
        while (q.size()) {
            tmp += q.front();
            q.pop_front();
        }
        for (int i = n; i >= 1; i--) {
            if (used[tmp[i]-'a'] >= 2 || cnt < k) {
                if (used[tmp[i]-'a'] >= 2) --n;
                else ++cnt,--n;
                --used[tmp[i]-'a'];
            }else{
                break;
            }
        }
        for (int i = 1; i <= n; i++) cout << tmp[i];
        cout << '\n';
    }
    return 0;
}