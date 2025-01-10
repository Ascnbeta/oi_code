#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod=1e9+7;
ll T,n,m,v,c,cnt,st,ans=1;
ll he[200005],in[100005];
bool vis[100005];
struct edge{
	ll to,ne,fr;
}e[200005];
void add(ll x,ll y){
	e[++cnt].to=y;
	e[cnt].fr=x;
	e[cnt].ne=he[x];
	he[x]=cnt;
}
void dfs(ll p){
	vis[p]=1;
	for(int i=he[p];i;i=e[i].ne){
		if(vis[e[i].to])
			continue;
		if(in[e[i].to]>1)
			ans=(ans*(in[e[i].to]-1)+mod)%mod;
		dfs(e[i].to);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=1;
		ll k;
		cin>>n>>k;
//		v=v%mod;
		memset(e,0,sizeof(e));
		memset(he,0,sizeof(he));
		memset(in,0,sizeof(in));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
			in[x]++;
			in[y]++;
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=k;i++)
			cin>>st;
		dfs(e[st].to);
		dfs(e[st].fr);
		cout<<(2*ans*k)%mod;
	}
	return 0;
}
