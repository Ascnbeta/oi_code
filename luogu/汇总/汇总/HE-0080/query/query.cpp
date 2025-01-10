#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
const int MOD=1e9+7;
int n;
int u,v;
int q;
int l,r,k;
int fa[N];
int main(){
	freopen("query.in","w",stdin);
	freopen("query.out","r",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		fa[v]=u;
	}
	while(q--){
		cin>>l>>r>>k;
		cout<<r-l+1<<'\n';
	}
	return 0;
}
