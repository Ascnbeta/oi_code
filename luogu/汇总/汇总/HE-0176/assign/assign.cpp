#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
const int N=1e5+7;
int n,m,v; 
struct li{
	int c,d;
}t[N];
int ksm(int x,int k){
	int res=1; 
	while(x){
		res=x*res%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>v;
		if(v==2){
			
			continue;
		}
		if(m==1){
			int c,d;
			cin>>c>>d;
			cout<<ksm(c-1,v)+ksm(n-c,v)<<'\n';
			continue;
		}
	} 
	return 0;
}
