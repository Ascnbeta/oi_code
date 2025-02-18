#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> e[30];
bool vis[30];
int ind[30],tmp[30];
int idx[30];
struct node{
	int p,cnt;
};
queue<node> q;
inline void topo(int p) {
	bool x = true;
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n; i++) tmp[i] = ind[i],idx[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (!tmp[i]) {
			q.push({i,1});
			if (idx[1] != 0) {
				x = false;
			} 
			idx[1] = i;
		}
	}
	while (!q.empty()) {
		node u = q.front();
		// cout << u << '\n';
		q.pop();
		vis[u.p] = true;
		for (auto v : e[u.p]) {
			--tmp[v];
			if (!tmp[v]) {
				q.push({v,u.cnt+1});
				if (idx[u.cnt+1] != 0) x = false;
				idx[u.cnt+1] = v;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) ++cnt;
	}
	if (cnt < n) {
		printf("Inconsistency found after %d relations.",p);
		exit(0);
	}
	if (x) {
		printf("Sorted sequence determined after %d relations: ",p);
		for (int i = 1; i <= n; i++) {
			cout << (char)(idx[i]+'A'-1);
		}
		cout << "." << '\n';
		exit(0);
	}
}
int main () {
#ifdef LOCAL
	freopen("D:\\codes\\exe\\a.in","r",stdin);
	freopen("D:\\codes\\exe\\a.out","w",stdout);
#endif
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		char u,v;
		scanf("\n%c<%c",&u,&v);
		e[u-'A'+1].push_back(v-'A'+1);
		++ind[v-'A'+1];
		topo(i);
	}
	puts("Sorted sequence cannot be determined.");
	return 0;
}