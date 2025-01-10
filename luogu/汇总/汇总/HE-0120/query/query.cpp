#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const ll mod=1e9+7;
int n;
int u[N],v[N];
vector<int> son[N];
int dep[N];
inline void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i:son[x]){
		dfs(to,x);
	}
}
inline void solve(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		son[u[i]].push_back(v[i]);
	}
	int q;
	scanf("%d",&q);
	dfs(1,0);
	while(q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		int ans=0;
		for(int i=l;i<=r;i++){
			ans=max(ans,dep[i]);
		}
		cout<<ans<<endl;
	}
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int _;
	scanf("%d",&_);
	while(_--) solve();
	return 0;
}
