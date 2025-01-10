#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		vector<int> u(n,0);
		vector<int> v(n,0);
		vector<int> e(k+1,0);
		for(int i=1;i<=n-1;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&e[i]);
		}
		cout<<v[k]<<endl;
	}
	
	return 0;
}
