#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<int> v;
bool p[100000004];
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) v.push_back(i);
        for (int j = 0; j < v.size() && v[j] * i <= n; j++) {
            p[i*v[j]] = true;
            if (i % v[j] == 0) break;
        }
    }
    while(q--) {
        int k;
        cin >> k;
        cout << v[k-1] << '\n';
    }
    return 0;
}