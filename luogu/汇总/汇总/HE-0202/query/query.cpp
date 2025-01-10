#include <iostream>
using namespace std;
int n,q,l,r,k,u[100009],v[100009];
int main() {
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> u[i] << v[i];
    }
    cin >> q;
    for(int i = 1;i <= q;i++) {
        cin >> l >> r >> k;
    }
    return 0;
}
