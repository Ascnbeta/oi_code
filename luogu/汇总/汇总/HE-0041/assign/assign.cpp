#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int t,n,m,v,ans;
struct node{
	int p,d;
}h[200005];
bool cmp(node a,node b){
	return a.p<b.p;
}
int binpow(int a,int b){
	if(!b) return 1;
	int res=binpow(a,b/2);
	if(b&1) return res*res%mod*a%mod;
	else return res*res%mod;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m>>v;
		ans=1;
		for(int i=1;i<=m;i++){
			cin>>h[i].p>>h[i].d;
		}
		sort(h+1,h+1+m,cmp);
		ans=ans*binpow(v,(h[1].p-1)*2)%mod;
		ans=ans*binpow(v,(n-h[m].p)*2)%mod;
		for(int i=2;i<=m;i++){
			if(h[i].p==h[i-1].p){
				if(h[i].d!=h[i-1].d){
					ans=0;
				    break;
				}else{
					continue;
				}
			}
			ans=ans*((binpow(v,(h[i].p-h[i-1].p)*2)-binpow(v,h[i].p-h[i-1].p-1)*(v-1)%mod)%mod+mod)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
