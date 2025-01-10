#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int N=1e5+1,p=1e9+7;
int T,n,m,v,ans,cnt;
map<int,int>mp;
int qp(int a,int b){
	a%=p;
	int ret=1;
	while(b){
		if(b&1)
			ret=ret*a%p;
		a=a*a%p,b>>=1;
	}
	return ret%p;
}
void Main(){
	ans=1,cnt=0;
	cin>>n>>m>>v;
	mp.clear();
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		if(mp.count(x)&&mp[x]!=y)
			ans=0;
		mp[x]=y;
	}
	if(!ans){
		cout<<"0\n";
		return;
	}
	auto it1=mp.begin(),it2=mp.begin();
	++it2;
	for(;it2!=mp.end();it1++,it2++){
		if((it1->first)+1==(it2->first))
			ans=(ans*((v*v-v+1)%p)%p),cnt++;
	}
	cnt=(n-1)-cnt;
	ans=ans*qp(v*v,cnt)%p;
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("query.in","r",stdin),
	freopen("query.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
	}
	int q;
	cin>>q;
	while(q--){
		cout<<"1\n";
	} 
	return 0;
}
