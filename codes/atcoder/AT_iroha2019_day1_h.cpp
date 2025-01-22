#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int g(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}//统计各数位之和
string t(int y) {
    string ret = "";
    int x = y / 9;
    if (y % 9 != 0) ret += y % 9 + '0';
    while(x--) ret += '9';
    return ret;
}//生成各数位之和为nn的数字X
signed main () {
    cin >> n;
    int nn = g(n);
    string s = t(nn);
    //cout << s << '\n';
    if (stoll(s) == n) {//如果X == N
        if (s.size() == 1) {
            s[0] -= 1;
            s = '1' + s;//对于1<=N<=9的数，在最前面补1，个位上的数减1
        }else{
            if (s[0] == '9') {
                s[0] -= 1;
                s = '1' + s;//对于各数位上全是9的数，将最高位减1，再在数字前补1
            }else{
                s[1] -= 1;
                s[0] += 1;//对于除最高位上全是9的数，次高位减1，最高位加1
            }
        }
        cout << s;
    }else{
        cout << s;
    }
    return 0;
}