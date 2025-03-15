#include <bits/stdc++.h>
using namespace std;
const int maxn = 13;
const int maxm = 103;
int n,m;
int a[maxm][maxn];
vector<int> e[1<<maxn];
bool vis[1<<maxn];
queue<int> q;
int dis[1<<maxn];
inline void print(int x) {
	stack<int> st;
	while (x) {
		st.push(x%2);
		x/=2;
	}
	while (st.size() < m) {
		st.push(0);
	}
	while (st.size()) {
		cout << st.top();
		st.pop();
	}
    cout << ' ';
}
inline void bfs(int s) {
    q.push(s);
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto v : e[u]) {
            // print(u);print(v);puts("");
            if (vis[v]) continue;
            vis[v] = true;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 1; j <= m; j++) {
            int tmp = i;
            for (int k = 1; k <= n; k++) {
                int t = a[j][k];
                // print((~(1<<(n-1))));
                // cout << '\n';
                if (t == 1) {
                    if ((tmp>>(k-1))&1) tmp -= (1<<(k-1));
                }
                else if(t == -1) tmp |= (1<<(k-1));
            }
            e[i].push_back(tmp);
        }
    }
    bfs((1<<n)-1);
    if (dis[0] == 0) cout << -1 << '\n';
    else cout << dis[0] << '\n';
    return 0;
}