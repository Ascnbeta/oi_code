#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long T,n,m,maxn,ans,c[1000005],d[1000005],x[1000005],nut,p;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;++o){
		cin>>n>>m>>maxn;
		for(long long i=1;i<=m;++i){
			cin>>c[i]>>d[i];
			if(x[c[i]]==0||x[c[i]]==d[i])
			x[c[i]]=d[i];
			else p++;
		}
		if(p==0){
		for(int i=1;i<=maxn;i++)
			for(int j=1;j<=maxn;j++){
				for(int k=1;k<=n;k++){
					x[k]=j;
					x[c[i]]=d[i];
					if(x[k]==i&&x[k+1]==0)
					x[k+1]=j;
				}
				for(int k=1;k<=n;k++)
					if(x[k]==i&&x[k+1]==j&&k+1<=n)
						nut++;
				if(nut==n-1)ans++;
				nut=0;
			}
		cout<<ans%mod+1<<endl;
		}
		else cout<<"0";
		ans=0;p=0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}



