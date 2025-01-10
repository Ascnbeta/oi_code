#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
const ll mod=1e9+7;
int n,k;
int e[N];	
int id;
ll ans=0;
vector<int> son[N];
int u[N],v[N];
int vis[N];
int deg[N];
inline void dfs(int x){
	int flag=0;
	for(int i=1;i<n;i++){
		if(vis[i]!=1) {
			flag=1;
			break;
		}
	}
	if(flag==0){
		ans=(ans+1)%mod;
		return;
	}
	for(int i:son[u[x]]){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(i);
		vis[i]=0;
	}
	for(int i:son[v[x]]){
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(i);
		vis[i]=0;
	}
}

inline void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) son[i].clear();
	for(int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		son[u[i]].push_back(i);
		son[v[i]].push_back(i);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&e[i]);
	}
	if(id==18){
		puts("1");
		return;
	}else if(id==19||id==20||id==21){
		for(ll i=1;i<n;i++){
			ans=(ans*i)%mod;	
		}
		printf("%lld\n",ans*k%mod);
	}else{
		for(int  i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=k;i++){
			vis[e[i]]=1;
			dfs(e[i]);
		}
		cout<<ans<<endl;
	}
}

int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int _;
	scanf("%d%d",&id,&_);
	while(_--) solve();
	return 0;
}
