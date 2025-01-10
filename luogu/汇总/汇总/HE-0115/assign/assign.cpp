#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a=1000000007;
int c[100005];
int d[100005];
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int t;
	scanf("%lld",&t);
	for(int ii=1;ii<=t;ii++)
	{
		int n,m,u;
		scanf("%lld%lld%lld",&n,&m,&u);
		for(int i=1;i<=m;i++)
		{
			scanf("%lld%lld",&c[i],&d[i]);
		}
		if(d[1]==1){
			cout<<"1"<<endl;
			continue;
		}
		if(m==n){
			n--;
			cout<<n<<endl;
		}
	}
}
