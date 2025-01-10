#include<bits/stdc++.h>
using namespace std;
int n,u,v,q,l,r,k;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);

		cin>>n;
		for(int i=1;i<=n-1;i++)
			cin>>u>>v; 
		cin>>q;
		for(int i=1;i<=q;i++){
			cin>>l>>r>>k;
			cout<<k<<endl;
		}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
