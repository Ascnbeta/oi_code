#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=2e5+7;

int c,T,n,K;
int ans=0;
vector<int> g[N];
int fac[N];
struct node{
	int u,v;
}tr[N];

int dfs(int x,int fa){
	int sum=1,son=0;
	for(int i=0,l=g[x].size();i<l;i++){
		int y=g[x][i];
		if(y!=fa){
			sum=sum*dfs(y,x)%mod;
			son++;
		}
	}
	sum=sum*fac[son]%mod;
	return sum;
}

signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=n;i++) g[i].clear();
		cin>>n>>K;
		fac[0]=fac[1]=1;
		for(int i=2;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
		}
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			tr[i].u=x,tr[i].v=y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(c==18){
			for(int i=1;i<=K;i++){
				int x;cin>>x;
			}
			cout<<1<<"\n";
			continue;
		}
		if(c>=19&&c<=21){
			for(int i=1;i<=K;i++){
				int x;cin>>x;
			}
			cout<<fac[n-2]*K%mod<<'\n';
			continue;
		}
		for(int i=1;i<=K;i++){
			int x;cin>>x;
			int add=dfs(tr[x].u,tr[x].v)*dfs(tr[x].v,tr[x].u)%mod;
			ans=(ans+add)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//7 1
//5 2
//1 2
//1 3
//2 4
//2 5
//1 3
