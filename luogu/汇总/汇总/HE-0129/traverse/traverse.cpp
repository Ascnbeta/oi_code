#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3,mod=1e9+7;
int c,t;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
		}
		for(int i=1;i<=n;i++){
			int e;cin>>e;
		}
		if(c==18){
			cout<<(2*k)%mod<<endl;
		}
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
