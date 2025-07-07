#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,a[maxn<<2];
int l,r;
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    l=n+1,r=n;
    int cnt = 0;
    while (n--) {
        char ch,d;cin >> ch >> d;
        if (ch == 'A') {    
            if (d == 'L') {
                a[--l] = ++cnt;
            }else{
                a[++r] = ++cnt;
            }
        }else if(ch == 'D') {
            int k;cin >> k;
            if (d == 'L') {
                l += k;
            }else{
                r -= k;
            }
        }
    }
    for (int i = l; i <= r; i++) cout << a[i] << '\n';
    return 0;
}