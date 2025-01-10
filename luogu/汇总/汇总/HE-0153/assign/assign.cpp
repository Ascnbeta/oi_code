#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,M=1e5+5,N=1e9+5;
int t,n,m,v;
int flag=1,num=0;
int c[M],d[M];
int x[M],ans[M];
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>v;
		flag=1;num=1;
		for(int i=1;i<=n;i++) x[i]=0;
		for(int i=1;i<=n;i++) ans[i]=0;
		for(int i=1;i<=m;i++){
			cin>>c[i]>>d[i];	
			if(x[c[i]]!=0&&x[c[i]]!=d[i]){
				cout<<0<<endl;
				flag=0;break;
			}
			x[c[i]]=d[i];
		}
		if(flag==0) continue;
		if(v<=2){			
			for(int j=1;j<=m;j++){
				x[c[j]]=d[j];
			}			
			for(int i=1;i<=n;i++){
				for(int j=1;j<=v;j++){
					if(x[i]==j){
						for(int k=1;k<=v;k++){
							if(x[i]==0||x[i]==k){
								num++;num%=mod;
							}
						}
					}else if(x[i]!=j){
						num=(num+v)%mod;
					}	
				}
			}
			cout<<num<<endl;
		}
		else if(n==m){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					
				}
			}
		}	
	}
	
	return 0;
}
