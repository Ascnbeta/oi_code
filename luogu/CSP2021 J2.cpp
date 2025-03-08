#include <bits/stdc++.h>
using namespace std;
int n,q;
int a[8003];
struct op{
    int tp,x,y;
}o[200005];
int main () {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            o[i].tp = 1;
            int x,y;
            cin >> x >> y;
            o[i].x = x,o[i].y = y;
        }else{
            o[i].tp = 2;
            int x;
            cin >> x;
            o[i].x = x;
        }
    }
    for (int i = 1; i <= q; i++) {
        if (o[i+1].tp != 1) {

        }
    }
    return 0;
}