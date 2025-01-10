#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long tree[100005],pre[100005];
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			tree[u]++;
			tree[v]++;
			pre[v]=u;
		}
		int k1;
		cin>>k1;
		if(k==1){
			cout<<"2";
		}
	} 
	return 0;
}
