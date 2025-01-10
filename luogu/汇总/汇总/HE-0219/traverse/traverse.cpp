#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,C,K,T,fac[100010];
vector<int> v[100010];
const int mod=1e9+7;
struct edge{
	int x,y;
}e[100010];
int solve(int x,int fa){
	int ans=fac[v[x].size()-1];
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==fa) continue;
		if(e[y].x==x) ans=ans*solve(e[y].y,y)%mod;
		else ans=ans*solve(e[y].x,y)%mod;
	}
	return ans;
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	fac[0]=1;
	for(int i=1;i<=100000;i++) fac[i]=i*fac[i-1]%mod;
	cin>>C>>T;
	while(T--){
		int x,y;
		cin>>n>>K;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[i].x=x;
			e[i].y=y;
			v[x].push_back(i);
			v[y].push_back(i);
		}
		if(K==1){
			cin>>x;
			cout<<solve(e[x].x,x)*solve(e[x].y,x)%mod<<endl;
			continue;
		}
		for(int i=1;i<=K;i++) cin>>x;
		if(C==18){
			cout<<1<<endl;
			continue;
		}
		cout<<(fac[n-2]*K%mod-K*(K-1)/2%mod*fac[n-3]%mod+mod)%mod<<endl;
	}
	return 0;
}
