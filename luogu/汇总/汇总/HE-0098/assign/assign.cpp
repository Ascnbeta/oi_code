#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int sum1[100100],sum2[100100];
int a[100100],b[100100];
long long qpow(long long a,long long b,int mod){
	long long ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n,m,c;
		cin>>n>>m>>c;
		for(int i=1;i<=m;i++)cin>>a[i]>>b[i];
		int v=abs(a[1]-b[1]);
		if(m==1)cout<<qpow(2,a[1]+n+1,1000000007);
	}
}
