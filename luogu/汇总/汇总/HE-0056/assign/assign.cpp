#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7,mod=1e9+7;
int T,n,m,v;
int c[N],d[N];
map<int,int> x;
long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res%mod;
}
void solve()
{
	scanf("%d%d%d",&n,&m,&v);
	bool flag=0;
	int cnt=0;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&c[i],&d[i]);
		if(x[c[i]]!=d[i] && x[c[i]]!=0)
		{
			flag=1;
		}
		if(x[c[i]]==d[i]) continue;
		x[c[i]]=d[i];
		if(x[c[i]-1]!=0) ++cnt;
		if(x[c[i]+1]!=0) ++cnt;
	}
	if(flag==1) {
	for(int i=1;i<=m;++i) x[c[i]]=0;
		printf("0\n");
		return ;
	}
	long long res=ksm(ksm(v,2)%mod,n-1-cnt)%mod;
	res=res*ksm(((v-1)%mod*v%mod+1),cnt)%mod;
	printf("%lld\n",res);
	for(int i=1;i<=m;++i) x[c[i]]=0;
}

signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	solve();
	return 0;
}
