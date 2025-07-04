#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
const ll p = 131;
ll binpow[25];
unordered_map<ll,int> b;
int n,m;
string s;
inline ll h(string t) {
    ll ret = 0;
    for (int i = 0; i < t.size(); i++) {
         ret += t[i]*binpow[t.size()-i-1];
    }
    return ret;
}
int f[10004];
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    binpow[0] = 1;
    for (int i = 1; i <= 23; i++) binpow[i]=binpow[i-1]*p;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        b.insert({h(s),i});
    }
    for (int i = 1; i <= m; i++) {
        cin >> s;
        string bs = s;
        if (b.find(h(s)) != b.end()) {
            cout << -1 << '\n';
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            for (int k = 0; k < 26; k++) {
                if (k+'a' == bs[j]) continue;
                s[j] = k+'a';
                ll tmp = h(s);auto it = b.find(tmp);
                if (it != b.end()) {
                    if (f[(*it).second] != i) {
                        ++cnt;
                        f[(*it).second] = i; 
                    }
                }
            }
            s[j] = bs[j];
        }
        s = bs;
        for (int j = 0; j < s.size(); j++) {
            string ch = "";ch += s[j];
            s.erase(j,1);
            ll tmp = h(s);auto it = b.find(tmp);
            if (it != b.end()) {
                if (f[(*it).second] != i) {
                    ++cnt;
                    f[(*it).second] = i; 
                }
            }
            s.insert(j,ch);
        }
        for (int j = 0; j < s.size(); j++) {
            for (int k = 0; k < 26; k++) {
                string ch = "";ch += k+'a';
                s.insert(j,ch);
                ll tmp = h(s);auto it = b.find(tmp);
                if (it != b.end()) {
                    if (f[(*it).second] != i) {
                        ++cnt;
                        f[(*it).second] = i; 
                    }
                }
                s.erase(j,1);
            }
        }
        for (int k = 0; k < 26; k++) {
            s += k+'a';
            ll tmp = h(s);auto it = b.find(tmp);
            if (it != b.end()) {
                if (f[(*it).second] != i) {
                    ++cnt;
                    f[(*it).second] = i; 
                }
            }
            s.erase(s.size()-1,1);
        }
        cout << cnt << '\n';
    }
    return 0;
}