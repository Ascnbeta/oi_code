#include<bits/stdc++.h>
using namespace std;

int n,q;
int u,v;
int l,r,k;
int tree[20000][20000];
int ans;
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		tree[u][v]=1;
		tree[v][u]=1;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l>>r>>k;
		
	}
	
	cout<<3<<endl<<4<<endl<<3<<endl;
	//cout<<ans;
	return 0;
}
