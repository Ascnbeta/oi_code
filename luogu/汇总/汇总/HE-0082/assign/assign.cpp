#include<bits/stdc++.h>
using namespace std;
long long t,n,m,v,c[100005],d[100005],x[100005],a[100005],b[100005],ans,tong[100005],flag;
void dfs(int i,int num){
	if(i==num){
		for(int ii=1;ii<=n;ii++) x[ii]=0;
		for(int ii=1;ii<=m;ii++){
			x[c[ii]]=d[ii];
//			cout<<c[ii]<<" "<<d[ii]<<'\n';
		}
		for(int ii=1;ii<n;ii++){
			if(x[ii]==a[ii]&&x[ii+1]!=b[ii]){
//				cout<<a[ii]<<" "<<b[ii]<<" "<<x[ii+1]<<'\n'; 
				if(x[ii+1]==0) x[ii+1]=b[ii];
				else return;
			}
//			cout<<x[ii]<<" "<<a[ii]<<" "<<b[ii]<<'\n';
		}
		ans++;
		ans%=1000000007;
	}else{
		a[i]=1;
		b[i]=1;
		dfs(i+1,num);
		a[i]=1;
		b[i]=2;
		dfs(i+1,num);
		a[i]=2;
		b[i]=1;
		dfs(i+1,num);
		a[i]=2;
		b[i]=2;
		dfs(i+1,num);	
	}
	
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		flag=1;
		memset(tong,0,sizeof(tong));
		memset(x,0,sizeof(x));
		cin>>n>>m>>v;
		if(v<=2&&flag&&n<=15&&m<=15){
			for(int i=1;i<=m;i++){
				cin>>c[i];
				cin>>d[i];
				if(x[c[i]]&&x[c[i]]!=d[i]){
					cout<<0<<'\n';
					flag=0;
				}
				x[c[i]]=d[i];
			}
			ans=0;
			if(!flag) continue;
			dfs(1,n);
		}else if(m==1){
			ans=1;
			for(int i=1;i<=n*2-2;i++){
				ans*=v;
				ans%=1000000007;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
