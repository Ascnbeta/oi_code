#include<bits/stdc++.h>
using namespace std;
const long long maxn=10e9+7;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,v,c,d;
		long long ans=0;
		cin>>n>>m>>v;
		int x[n+1];
		memset(x,0,sizeof(x));
		for(int i=1;i<=m;i++){
			cin>>c>>d;
			x[c]=d;
		}
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++){
				int p=1;
				for(int k=1;k<=v;k++){
					if(x[k]==i){
						if(!((x[k+1]==j)||(x[k+1]==0))){
							p=0;
						}
					}
				}
				if(p)ans++;
			}
		}
		cout<<ans%maxn<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
