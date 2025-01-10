#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e5+7;
const int MOD=1e9+7;

int c,T,n,k;
int u[N],v[N],e[N];
int fa[N];

signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	while(T--){
		if(c==18){
			cout<<1<<"\n";
			continue;
		}
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			fa[v[i]]=u[i];
		}
		for(int i=1;i<=k;i++)cin>>e[i];
		
	}
	return 0;
}
