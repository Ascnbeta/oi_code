#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int T,n,m,v,ans;
int vis[100100],cnt;
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res%mod;
}
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	T=read();
	while(T--){
		map<int,int> mp;
		int cnt=0;
		bool flag=true;
		n=read(),m=read(),v=read();
		int p=n-1;
		int ans=1;
		for(int i=1;i<=m;i++){
			int c,d;
			c=read(),d=read();
			if(mp[c]!=d&&mp[c]!=0)flag=false;
			if(mp[c]==d)continue;
			if(d>v)flag=false;
			vis[++cnt]=c;
			mp[c]=d;
		}
		sort(vis+1,vis+cnt+1);
		for(int i=2;i<=cnt;i++){
			if(vis[i]==vis[i-1]){
				flag=false;
				break;
			}
			if(vis[i]==vis[i-1]+1){
				ans=ans%mod*(v*v-v+1)%mod;
				p--;
			}
		}
		ans=ans*ksm(v%mod*v%mod,p)%mod;
		if(!flag){
			cout<<0<<endl;
			continue;
		}
		cout<<ans%mod<<endl;
		for(int i=1;i<=cnt;i++)vis[i]=0;
	}
	return 0;
}
