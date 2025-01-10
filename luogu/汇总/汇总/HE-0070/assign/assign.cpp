#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+7;

int T,n,m,v;
int pos[N];
int ans,flagg;
map<int,int> vis;

int qpow(int x,int k){
	int sum=1;
	while(k){
		if(k&1) sum=sum*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return sum;
}

signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		ans=1,flagg=0;vis[pos[m]]=vis[pos[1]]=0;
		memset(pos,0,sizeof(pos));
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			int w;cin>>pos[i]>>w;
			if(vis[pos[i]]!=0&&vis[pos[i]]!=w) flagg=1;
			vis[pos[i]]=w;
		}
		sort(pos+1,pos+m+1);
		for(int i=2;i<=m;i++){                                     
			if(pos[i]==pos[i-1]) continue;
			ans=(qpow(v*v%mod,pos[i]-pos[i-1])-(v-1)*qpow(v,pos[i]-pos[i-1]-1)%mod+mod)%mod*ans%mod;
			vis[pos[i]]=0;
		}
		ans=ans*qpow(v*v%mod,n-pos[m]+pos[1]-1)%mod;
		if(v==1){
			cout<<1<<"\n";
			continue;
		}
		if(flagg){
			cout<<0<<"\n";
			continue;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
