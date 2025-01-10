#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;
const int N=1e5;
const long long M=1e9+7;
pair<int,int>c[N+5];
long long pw(long long x,long long y)
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
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int o=1;o<=T;o++)
	{
		int m;
		long long ans,n,v;
		scanf("%lld%d%lld",&n,&m,&v);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&c[i].first,&c[i].second);
		}
		sort(c+1,c+1+m);
		ans=pw(v*v%M,c[1].first-1);
		for(int i=1;i<m;i++)
		{
			if(c[i].first==c[i+1].first)
			{
				if(c[i].second!=c[i+1].second)
				{
					printf("0\n");
					goto ed;
				}
				else
					continue;
			}
			ans*=(pw(v*v%M,c[i+1].first-c[i].first)-pw(v,c[i+1].first-c[i].first-1)*(v-1)%M);
			ans%=M;
			if(ans<0)
				ans+=M;
		}
		ans*=pw(v*v%M,n-c[m].first);
		ans%=M;
		printf("%lld\n",ans);
//		printf("%lld\n",pw(v*v%M,n-1));
		ed:;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
557584238 1 464289274
309302662 462600170
817800451 1 578482625
689892411 37963033
*/
