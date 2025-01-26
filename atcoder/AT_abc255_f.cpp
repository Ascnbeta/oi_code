#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
int n;
int x[N],y[N],pos,yp[N];
int ch[N][3];
void dfs(int l,int r,int p,int lst) {
    if (lst != 0) {
        if (r < lst) {
            ch[y[lst]][1] = x[p];
        }else if (l > lst) {
            ch[y[lst]][2] = x[p];
        }
    }
    if (l == r) return;
    int root = yp[x[p]];
    if (root < l || root > r) {
        cout << -1 << endl;
        exit(0);
    }
    if (root != l) {
        dfs(l,root-1,p+1,root);
    }
    if (root != r) {
        dfs(root+1,r,p+root-l+1,root);
    }
}
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (x[1] != 1) {
            cout << -1 << endl;
            return 0;
        }else{
            pos = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        yp[y[i]] = i;
    }
    dfs(1,n,pos,0);
    for (int i = 1; i <= n; i++) {
        cout << ch[i][1] << ' ' << ch[i][2] << '\n';
    }
    return 0;
}