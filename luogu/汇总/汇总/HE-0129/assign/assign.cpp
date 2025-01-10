#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
const long long mod=1e9+7;
int val[maxn],g[maxn];
long long ans=0;
long long ksm(long long a,long long e){
	long long f=1;
	while(e){
		if(e%2==1)f=(f*a)%mod;
		a=(a*a)%mod;
		e/=2;
	}
	return f;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int t;cin>>t;
	while(t--){
		memset(val,0,sizeof(val));
		int n,m,v;cin>>n>>m>>v;
		bool flag=0,flag2=1;
		for(int i=1;i<=m;i++){
			int c;cin>>c;
			if(val[c]){
				flag=1;break;
			}
			cin>>val[c];
			if(val[c]!=1)flag2=0;
		}
		if(flag){
			cout<<0<<endl;continue;
		}
		if(m==1){
			cout<<ksm((v*v)%mod,n-1)<<endl;
		}
		else if(flag2){
			cout<<ksm(((v-1)*v)%mod,n-1)+1<<endl;
		}
		else if(m==n){
			cout<<ksm(((v-1)*v)%mod+1,n-1)<<endl;
		}
		else{
			ans=0;
			for(int i=1;i<=n;i++)g[i]=val[i];
			for(int i=1;i<=n-1;i++){
				for(int a=1;a<=v;a++){
					for(int b=1;b<=v;b++){
						if(g[i]==a&&(g[i+1]!=0&&g[i+1]!=b))continue;
						ans++;
						ans%=mod;
					}
				}
			}
			cout<<ans<<endl;	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
