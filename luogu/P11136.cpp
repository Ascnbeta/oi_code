#include <bits/stdc++.h>
using namespace std;
long long a,b,c,k,mod = 988444333;
int main () {
    cin >> a >> b >> c >> k;
    cout << (a + k) * (b + k) * (c + k) % mod <<endl;
    return 0;
}