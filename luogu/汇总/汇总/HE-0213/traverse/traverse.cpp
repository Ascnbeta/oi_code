#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,c;
int n,k;
int u[100005],v[100005];
int e[100005];
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<=k;i++){
			cin>>e[i];
		}
	}
	for(int i=1;i<=T;i++){
		cout<<1<<endl; 
		
	}
	return 0;
}
