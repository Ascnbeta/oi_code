#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5,MOD=1e9+7;
long long T,n,m,v;
bool flag;
long long qmi(long long a,long long b){
	long long res=1;
	while(b>0){
		if(b%2==1) res=res*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return res;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--){
		map<long long,long long> mp; 
		flag=0;
		cin>>n>>m>>v;
		for(int i=1,c,d;i<=m;i++){
			cin>>c>>d;
			if(mp[c]!=0&&mp[c]!=d){
				cout<<0<<'\n';
				flag=1;
				break;
			}
			mp[c]=d;
		}
		if(flag) continue;
		if(m==1) cout<<qmi(v*v%MOD,n-1)%MOD<<'\n';
		if(m==n) cout<<qmi((v*v-v+1)%MOD,n-1)%MOD<<'\n';
	} 
	return 0;
}
