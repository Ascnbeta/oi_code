#include<bits/stdc++.h>
using namespace std;
long long t,n,m,v,ans;
long long c[100010],x;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>v;
		ans=v*v;
		if(m==1){
			for(int i=1;i<n-1;i++){
				ans=ans*v*v%1000000007;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&x);

			if(c[x]!=0){
				int l;
				scanf("%lld",&l);
				if(l!=c[x]){
					ans=0;
				}
			}
			else{
				scanf("%lld",&c[x]);
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
