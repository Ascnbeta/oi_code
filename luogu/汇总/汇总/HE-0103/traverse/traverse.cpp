#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
int c,T,n,k,factor[N];
vector<int> G[N],key;
#undef int
int main(){
#define int long long
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=n;i++) G[i].clear();
		key.clear();
		int A=1,B=1;
		cin>>n>>k;
		factor[0]=1;
		for(int i=1;i<=n;i++) factor[i]=(i*factor[i-1])%mod;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			if(v!=u+1) A=0;
			if(u!=1) B=0;
			G[u].push_back(v);G[v].push_back(u);
		}
		for(int i=1;i<=k;i++){
			int e;cin>>e;
			key.push_back(e);
		}
		if(A) cout<<1<<endl;
		if(B) cout<<k*factor[n-1]%mod<<endl;
	}
	
	return 0;
}
