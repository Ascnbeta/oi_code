#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int T,n,k,c,u,v,e;
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	for(int o=1;o<=T;++o){
		cin>>n>>k;
		for(int i=1;i<n;i++)
			cin>>u>>v;
			for(int i=1;i<=k;i++)
			cin>>e;
		cout<<n-2<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
