#include <bits/stdc++.h>
#define int long long
using namespace std;
int x = 1,a,n,w;
bool vis[1000006];
struct num{
    int x,c;
};
queue<num> q;
void bfs(int m,int cnt) {
    vis[m] = true;
    q.push(num{m,cnt});
    while(!q.empty()) {
        num t = q.front();
        if (t.x == n) {
            cout << t.c << endl;
            exit(0);
        }
        q.pop();
        int p = t.x * a;
        if (p < w && p < 1000000 && !vis[p]) {
            vis[p] = true;
            q.push(num{p,t.c+1});
        }
        if (t.x < w && t.x >= 10 && t.x % 10 != 0) {
            int w1 = 0,tmp = t.x,o = 0;
            while(tmp) {
                tmp /= 10;
                w1++;
            }
            o += t.x % 10 * pow(10,w1-1);
            o += t.x / 10;
            if (!vis[o]) vis[o] = true,q.push(num{o,t.c+1});
        }
    }
}
signed main () {
    cin >> a >> n;
    int tmp = n;
    while (tmp) {
        tmp /= 10;
        w++;
    }
    w = pow(10,w);
    bfs(x,0);
    cout << -1 << endl;
    return 0;
}