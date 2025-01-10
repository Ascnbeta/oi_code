#include <bits/stdc++.h>
const int maxn = 1e6;
using namespace std;
int n, Q;
vector<int> d[maxn],da[maxn];
int dep[maxn] , u, v, l ,r ,k;
bool bo[511][511];
queue<int> q;
void dfsn(int x,int de,int fa) {
	dep[x] = de;
	for(int i=0;i<da[x].size();++i) {
		int to = da[x][i];
		if(to == fa) continue;
		dep[to] = de + 1;
		dfsn(to , de + 1 ,x);
	}
}
bool dfs(int x,int y) {
	queue<int> p;
	p.push(x);
	while(p.size()) {
		int to = p.front();
		if(to == y) return 1;
		p.pop();
		for(int i=0;i<d[to].size();++i) {
			int nex = d[to][i];
			if(nex == y) return 1;
			p.push(nex);
		}
	}
	return 0;
}
void solve1() {
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(dfs(i,j)) bo[i][j] = 1;
		}
	}
	cin >> Q;
	for(int i=1;i<=Q;++i) {
		cin >>l >> r >>k;
		int x = 0;
		for(int j=l;j<=r;++j) {
			for(int w=1;w<=n;++w){
				bool qp = 0;
				for(int z=1;z<=k;++z) {
					if(bo[w][j+z] == 0) {
						qp = 1;
						break;
					}
				}
				if(qp == 0) x = max(x,dep[w]); 
			}
		}
		cout << x << endl; 
	}
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n-1;++i) {
		cin >> u >> v;
		d[u].push_back(v);
		da[u].push_back(v);
		da[v].push_back(u);
	}
	dfsn(1, 1, 1);
	if(n <= 500) {
		solve1();
		return 0;
	}
	cin >> Q;
	for(int i=1;i<=Q;++i) {
		cin >>l >> r >>k;
		int x = 0;
		for(int j=l;j<=r;++j) {
			int man = 1e9+1;
			for(int z=1;z<=k;++z) {
				man = min(man, dep[j+z]);
			}
			x = max(x, man);
		}
		cout << x << endl; 
	}
}
