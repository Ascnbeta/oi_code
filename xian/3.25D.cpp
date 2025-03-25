#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> ans;
int main() {
#ifdef LOCAL
    freopen("E:/codes/exe/a.in","r",stdin);
    freopen("E:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> s;
    s = ' ' + s;
    if (n % 2 == 0) {
        puts("NOT POSSIBLE");
        return 0;
    }
    int i = 1,j = n/2+2;
    string tmp = "";
    for (;i <= n/2 && j <= n;++i,++j) {
        if (s[i] != s[j]) break;
        tmp += s[i];
    }
    if (i == n/2+1 && j == n+1) ans.push_back(tmp);
    i = 1,j = n/2+2;
    bool f = true;
    tmp = "";
    for (;i <= n/2+1 && j <= n; ) {
        if (s[i] != s[j]) {
            if (f) {
                f = false;
                ++i;
            }else{
                break;
            }
        }else{
            tmp += s[j];
            ++i,++j;
            
        }
    }
    if (j == n+1 && (ans.size()==0||ans[0] != tmp)) ans.push_back(tmp);
    i = 1,j = n/2+1;
    f = true;
    tmp = "";
    for (;i <= n/2 && j <= n; ) {
        if (s[i] != s[j]) {
            if (f) {
                f = false;
                ++j;
            }else{
                break;
            }
        }else{
            tmp += s[i];
            ++i,++j;
            
        }
    }
    if (i == n/2+1 && (ans.size()==0||ans[0] != tmp) && (ans.size()<=1||ans[1] != tmp)) ans.push_back(tmp);
    if (ans.size() > 0) {
        if (ans.size() == 1) cout << ans[0] << '\n';
        else puts("NOT UNIQUE");
    }else{
        puts("NOT POSSIBLE");
    }
    return 0;
}