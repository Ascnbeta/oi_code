#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10,mod=1e9+7;
unsigned long long T,n,m,v,ans;
struct node{
	long long c,d;
}cd[M];
bool cmp(node a,node b){
	return a.c<b.c;
}
long long qp_ow(long long a,long long b){
	long long _=1;
	for(;b;b>>=1){
		if(b&1) _=_*a%mod;
		a=a*a%mod;
	}
	return _;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m>>v;
		for(long long i=1;i<=m;i++) cin>>cd[i].c>>cd[i].d;
		sort(cd+1,cd+n+1,cmp);
		long long now=1,tot=0,ok=0,flag;
		ans+=qp_ow(v*v,n-1);
		for(long long i=1;i<m;i++){
			if(cd[i].c+1==cd[i+1].c) tot=(tot+1)%mod;
			else if(cd[i].c==cd[i+1].c && cd[i].d!=cd[i+1].d){
				ans=0;
				ok=1;
				break;
			}
		}
		if(ok!=1) ans=ans-(v-1)%mod*tot%mod;
		cout<<ans<<'\n';
	}
	return 0;
}
