#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
const int LOGN = 22;
int s[N << 1],pos[N],dep[N],top;


namespace Graph{
	struct edge{
		int v;
		int next;
	}e[N << 1];
	int head[N];
	int cur = 0,maxdep = 0;
	
	inline void addedge(int u,int v){
		e[++ cur].v = v;
		e[cur].next = head[u];
		head[u] = cur;
	}
	
	inline void dfs_euler(int u,int fa){
		dep[u] = dep[fa] + 1;
		maxdep = max(maxdep,dep[u]);
		s[++ top] = u;
		pos[u] = top;
		
		for(int i = head[u];i;i = e[i].next){
			int v = e[i].v;
			if(v == fa) continue;
			dfs_euler(v,u);
			s[++ top] = u;
		}
	}
}

namespace ST{
	int data[N][LOGN],logn[N << 1];
	inline int Ckmin(int x,int y){
		return dep[x] < dep[y] ? x : y;
	}
	
	inline void build(int n){
		for(int i = 2;i < (N << 1);++ i) logn[i] = logn[i >> 1] + 1;
		for(int i = 1;i <= n;++ i) data[i][0] = s[i];
		for(int s = 1;s < LOGN;++ s){
			for(int l = 1;l + (1 << s) - 1 <= n;++ l){
				data[l][s] = Ckmin(data[l][s - 1],data[l + (1 << (s - 1))][s - 1]);
			}
		}
	}
	
	inline int query(int l,int r){
		l = pos[l],r = pos[r];
		if(l > r) swap(l,r);
		int s = logn[r - l + 1];
		return Ckmin(data[l][s],data[r - (1 << s) + 1][s]);
	}
}

namespace ST2{
	int data[N][LOGN],logn[N << 1];
	inline int Ckmin(int x,int y){
		return dep[x] < dep[y] ? x : y;
	}
	
	inline void build(int n){
		for(int i = 2;i < (N << 1);++ i) logn[i] = logn[i >> 1] + 1;
		for(int i = 1;i <= n;++ i) data[i][0] = i;
		for(int s = 1;s < LOGN;++ s){
			for(int l = 1;l + (1 << s) - 1 <= n;++ l){
				data[l][s] = ST::query(data[l][s - 1],data[l + (1 << (s - 1))][s - 1]);
			}
		}
	}
	
	inline int query(int l,int r){
		int s = logn[r - l + 1];
		return ST::query(data[l][s],data[r - (1 << s) + 1][s]);
	}
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n;
	for(int i = 1;i < n;++ i){
		int u,v;
		cin>>u>>v;
		Graph::addedge(u,v);
		Graph::addedge(v,u);
	}
	Graph::dfs_euler(1,0);
	assert(top == n * 2 - 1);
	ST::build(n * 2 - 1);
	ST2::build(n);
	cin>>q;
	while(q --){
		int l,r,k;
		cin>>l>>r>>k;
		int ans = 0;
		for(int i = l;i + k - 1 <= r;++ i) ans = max(ans,dep[ST2::query(i,i + k - 1)]);
		cout<<ans<<"\n";
	}
	return 0;
}
