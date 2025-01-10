#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,v,t;
const int mod=1e9+7;
int c,d;
int qm(int a,int n){
	if(n==1) return a;
	if(n%2==0){
		int t=qm(a,n/2)%mod; return t%mod*t%mod;
	}else{
		int t=qm(a,n/2)%mod; return t%mod*t%mod*a%mod;
	}
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>c>>d;
		}
	//	if(m==1){
			int ans=1;
			cout<<qm(v,2*n-2)<<endl; continue;
	//	}
		
	}
	return 0;
}
