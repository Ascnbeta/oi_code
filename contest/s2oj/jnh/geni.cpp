#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int n = 300000,m = 500000;
mt19937 r(GetTickCount());
vector<int> f;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","w",stdout);
#endif
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= m; i++) {
        int op = r()%10;
        if (op >= 0 && op <= 6) {
            int pos = r()%n+1,s = r()%10000+90000,a = r()%10000+90000;
            cout << 'P' << ' ' << pos << ' ' << s << ' ' << a << '\n';
            f.push_back(pos);
        }else if(op >= 7 && op <= 8) {
            int pos = -1;
            if (f.size()) pos = r()%(int)f.size();
            if (pos == -1) {
                pos = r()%n+1;int s = r()%10000+90000,a = r()%10000+90000;
                cout << 'P' << ' ' << pos << ' ' << s << ' ' << a << '\n';
            }else{
                cout << 'U' << ' ' << f[pos] << '\n';
                f.erase(f.begin()+pos);
            }
        }else if(op == 9) {
            int ll = r()%n+1,rr = r()%n+1;
            if (ll > rr) swap(ll,rr);
            cout << 'Z' << ' ' << ll << ' ' << rr << '\n';
        }
    }
    return 0;
}