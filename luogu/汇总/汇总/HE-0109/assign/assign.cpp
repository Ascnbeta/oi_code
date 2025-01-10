#include<bits/stdc++.h>
const int MOD = 1e9+7;
using namespace std;
int c[100005],d[100005],fla,hhh,T;
int main() {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T; 
	for(int dfgz=1;dfgz<=T;dfgz++){
		fla=0;hhh=0;
		long long n,m,v;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++) {
			c[i]=d[i]=0;
		}
		for(int i=1;i<=m;i++) {
			cin>>c[i]>>d[i];
		}
		long long kkkk=v*v-v+1,sum=1;
		kkkk%=MOD;
		for(int i=1;i<m;i++) {
			sum*=kkkk; sum%=MOD;
		}
		printf("%lld\n",sum);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

