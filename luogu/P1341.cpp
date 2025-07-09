#include <bits/stdc++.h>
using namespace std;
int n;
int e[130][130];int deg[130],cnt,st;
string s;
void dfs(int u) {

    for (int i = 1; i <= 129; i++) {
        if (e[u][i]) {
            e[u][i]--;e[i][u] --;
            dfs(i);
        }
    }
    s += u;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char x,y;cin >> x >> y;
        e[x][y]++,e[y][x]++,deg[x]++,deg[y]++;
    }
    for (int i = 1; i <= 129; i++) if (deg[i] % 2 == 1) ++cnt;
    if (cnt != 0 && cnt != 2) {
        puts("No Solution");
        return 0;
    }
    if (cnt == 2) {
        for (int i = 1; i <= 129; i++) if (deg[i]%2==1) {st=i;break;}
    }else{
        for (int i = 1; i <= 129; i++) if(deg[i]) {st=i;break;}
    }
    dfs(st);
    if (s.size() != n+1) puts("No Solution");
    else reverse(s.begin(),s.end()),cout << s << '\n';
    return 0;
}