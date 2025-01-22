#include <bits/stdc++.h>
using namespace std;
int n;
long long num[10];
map <string,int> ard;
bool check (string s) {
    int p1 = -1,cnt1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ++cnt1;
            if (cnt1 > 3) return false;
            if (p1 != -1) {
                if (i - p1 == 1) return false;
            }
            string tmp = s.substr(p1+1,i-p1-1);
            if (tmp.size() == 0) return false;
            //cout << tmp << endl;
            long long x = stoll(tmp);
            if (x < 0 || x > 255) return false;
            p1 = i;
            num[cnt1] = x;
        }else if(s[i] == ':'){
            ++cnt1;
            if (cnt1 != 4) return false;
            if (i - p1 == 1) return false;
            string tmp = s.substr(p1+1,i-p1-1);
            if (tmp.size() == false) return false;
            //cout << tmp << endl;
            long long x = stoll(tmp);
            if (x < 0 || x > 255) return false;
            p1 = i;
            num[cnt1] = x;
        }else if (i == p1 + 1) {
            if (s[i] == '0' && i != s.size() - 1 && s[i+1] != '.' && s[i+1] != ':') return false;
        }
    }
    ++cnt1;
    if (cnt1 != 5) return false;
    string tmp = s.substr(p1+1,s.size()-1);
    if (tmp.size() == 0) return false;
    long long  x = stoll(tmp);
    if (x < 0 || x > 65535) return false;
    num[cnt1] = x;
    return true;
}
int main () {
    //freopen("3.in","r",stdin);
    //freopen("ans.out","w",stdout);
    cin >> n;
    int m = n;
    while (n--) {
        string tp;
        cin >> tp;
        if (tp == "Server") {
            string ad;
            cin >> ad;
//            cout << ad << endl;
            if (!check(ad)) {
                puts("ERR");
                continue;
            }
            if (ard.find(ad) != ard.end()) {
                puts("FAIL");
                continue;
            }
            ard.insert(make_pair(ad,m-n));
            puts("OK");
        }else if (tp == "Client") {
            string ad;
            cin >> ad;
            if (!check(ad)) {
                puts("ERR");
                continue;
            }
            if (ard.find(ad) == ard.end()) {
                puts("FAIL");
                continue;
            }
            cout << ard[ad] << '\n';
        }
    }
    return 0;
}