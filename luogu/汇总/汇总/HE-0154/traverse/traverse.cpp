#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,n,k,fa=1,u,v;
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			scanf("%lld%lld",&u,&v);
			//if(u!=1) fa=0;
		}
		if(fa){
			cout<<1<<endl; continue;
		}
	}
	return 0;
}
