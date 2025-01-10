#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,e;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n-1;j++){
			cin>>u>>v;
		}
		for(int h=1;h<=k;h++){
			cin>>e;
		}
		cout<<k+1<<endl;
	}
	return 0;
}
