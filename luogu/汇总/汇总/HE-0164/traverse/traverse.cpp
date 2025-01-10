#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	long long c,T,n,k;
	while(T--){
		cin>>n>>k;
		bool ok=0;
		for(long long i=1;i<n;i++){
			long long u,v;
			cin>>u>>v;
			if(u!=1) ok=1;
		}
		if(ok==0) cout<<'1'<<'\n';
		else cout<<n-1<<'\n';
	}
	return 0;
}
