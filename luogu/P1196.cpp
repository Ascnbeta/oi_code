#include <bits/stdc++.h>
using namespace std;
const int n = 30000;
int T;
int father[30004],size[30004],d[30004];
inline int find(int x) {
    if (x != father[x]) {
        int tmp = father[x];
        father[x] = find(father[x]);
        if (size[x] != size[tmp]) {
            size[x] = size[tmp];
            d[x] += d[tmp] - 1; 
        }
    }
    return father[x];
}
inline void merge(int i,int j) {
    int p = find(i),q = find(j);
    if (p == q) return;
    father[p] = q;
    d[p] = size[q] + 1;
    size[q] += size[p];
    size[p] = size[q];
}
int main () {
    cin >> T;
    for (int i = 1; i <= n; i++) father[i] = i,size[i] = 1,d[i] = 1;
    while (T--) {
        char op;int i,j;
        cin >> op >> i >> j;
        if (op == 'M') merge(i,j);
        if (op == 'C') {
            if (find(i) != find(j)) {
                cout << -1 << '\n';
            }else{
                cout << abs(d[i]-d[j])-1 << '\n';
            }
        }
    }
    return 0;
}
