#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,mod=1e9+7;
int n,m,t,v,tot,f[N];
struct node{
	int id,w;
	bool operator<(const node&x)const{
		return id<x.id;
	}
}a[N],qr[N];
int ksm(int x,int y){
	if(!y) return 1;
	if(y<0) return 0;
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		tot=0;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++) cin>>a[i].id>>a[i].w;
		sort(a+1,a+m+1);
		int flag=1;
		for(int i=1;i<m;i++){
			if(a[i].id==a[i+1].id){
				if(a[i].w!=a[i+1].w){
					flag=0;
					break;
				}
			}
		}
		if(!flag){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=m;i++){
			if(a[i-1].id==a[i].id) continue;
			qr[++tot]=a[i];
		}
		if(tot==1){
			cout<<ksm(v,2*(n-1))<<'\n';
			continue;
		}
		if(n==tot){
			for(int i=1;i<=n;i++) f[i]=0;
			cout<<ksm(v*(v-1)+1,n-1)<<'\n';
			continue;
		}
	}
}