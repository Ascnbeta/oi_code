#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e5;
const long long M=1e9+7;
int cnt[N+5];
long long pw[N*2+5],aw[N*2+5],s[N+5];
vector<int>e[N+5];
long long pwr(long long x,long long y)
{
	long long ans=1;
	for(long long p=x,s=1;y;p=p*p%M,s<<=1)
	{
		if(s&y)
		{
			y&=(~s);
			ans*=p;
			ans%=M;
		}
	}
	return ans;
}
void que(int nd,int fa)
{
	int d=e[nd].size();
	for(int i=0;i<d;i++)
	{
		if(e[nd][i]==fa)
			continue;
		cnt[nd]++;
		que(e[nd][i],nd);
	}
}
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	pw[0]=1;
	aw[0]=1;
	s[0]=1;
	for(int i=1;i<=(N<<1);i++)
	{
		pw[i]=pw[i-1]*i%M;
//		printf("%lld\n",pw[i]);
	}
	for(int i=1;i<=(N<<1);i++)
	{
		aw[i]=pwr(pw[i],M-2);
	}
	for(int i=1;i<=N;i++)
	{
		s[i]=((pw[i<<1]*aw[i]%M*aw[i])-i-1+M)%M;
//		printf("%lld\n",s[i]);
	}
	s[1]=1;
	int c,T;
	scanf("%d%d",&c,&T);
	for(int o=1;o<=T;o++)
	{
		int n,k;
		long long ans=0,p=1;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		que(1,0);
		cnt[1]--;
		for(int i=1;i<=n;i++)
		{
			p*=s[cnt[i]];
			p%=M;
		}
//		printf("%lld\n",p);
		for(int i=1;i<=k;i++)
		{
			int e;
			scanf("%d",&e);
//			printf("%lld\n",s[cnt[e]+1]);
			ans+=p*pwr(s[cnt[e]],M-2)%M*s[cnt[e]+1]%M;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			e[i].clear();
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}
