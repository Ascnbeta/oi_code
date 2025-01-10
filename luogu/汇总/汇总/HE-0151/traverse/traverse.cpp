#include<bits/stdc++.h>
using namespace std;

int c,T;
int n,k;
vector<pair<int,int> > tree;
int vis[100005];
int e[100005];
int ans;
int mod=1e9+7;

void tr(int b,int e){
	int flag=1;
	vis[b]=1;
	for(int i=1;i<=n-1;i++){
		if(vis[i]!=1)	flag=0;
		if(e==b && flag==1){
			ans=(ans+1)%mod;
		return; 
	} 
	}
	
	for(int j=1;j<=n-1;j++){
		if(vis[j]!=1 && (tree[e].first==tree[j].first || tree[e].first==tree[j].second)){
			vis[j]=1;
			tr(b,j);
			vis[j]=0;
		}
	}
}

int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);

	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			tree.push_back(make_pair(u,v));
		}
		for(int i=1;i<=k;i++){
			cin>>e[i];
		}
		
		for(int i=1;i<=k;i++){
			tr(e[i],e[i]);
		}
		
		cout<<ans+1<<endl;
	}
	return 0;
}
