#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	cin>>n;
	vector<int> u(n,0);
	vector<int> v(n,0);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u[i],&v[i]);
	}
	int q;
	cin>>q;
	int l,r,k;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",k);
	}
	
	return 0;
}
