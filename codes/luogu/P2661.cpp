#include <bits/stdc++.h>
using namespace std;
int n,ans = 0x3f3f3f3f;
int father[200005],v[200005],cnt;
inline int find(int x) {
    if (father[x] != x) {
        int lst = father[x];
        father[x] = find(father[x]);
        v[x] += v[lst];
    }
    return father[x];
}
inline void merge(int x,int y) {
    int p = find(x);
    int q = find(y);
    if (p != q) {
        father[p] = q;
        v[x] = v[y] + 1;
    }else{
        ans = min(ans,v[x]+v[y]+1);
    }
}
int main () {
    cin >> n;
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        merge(i,t);
    }
    cout << ans << '\n';
    return 0;
}