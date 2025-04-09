#include < 
using namespace std;
const int maxn = 3e6+10;
int n,k;
int b[maxn];
struct edge{
    int v,w;
};
vector<edge> e[maxn];
vector<int> c[maxn];
int dis[maxn];
deque<int> q;
inline void bfs(int s) {
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    q.push_front(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto i : e[u]) {
            int v = i.v,w = i.w;
            if (dis[v] != 0x3f3f3f3f) continue;
            if (w == 0) {
                dis[v] = dis[u];
                q.push_front(v);
            }else if(w == 1) {
                dis[v] = dis[u]+1;
                q.push_back(v);
            }
        }
    }
    if (dis[k*n+n] != 0x3f3f3f3f) cout << dis[k*n+n] << '\n';
    else cout << -1 << '\n';
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        e[(b[i]-1)*n+i].push_back({k*n+i,0});
        c[b[i]].push_back(i);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            char x;
            cin >> x;
            if (x == '1') {
                for (auto v : c[i]) {
                    e[k*n+v].push_back({(j-1)*n+v,0});
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            e[i*n+j].push_back({i*n+j+1,1});
            e[i*n+j+1].push_back({i*n+j,1});
        }
    }
    bfs(k*n+1);
    return 0;
}