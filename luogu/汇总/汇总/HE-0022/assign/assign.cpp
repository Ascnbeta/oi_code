#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
const int N=1e5+10,mod=1e9+7;
struct node
{
	int c,d;
}e[N];
int T,n,m,v;
map<int,int>mp;
void cl()
{
	mp.clear();
}
int qp(int x,int y,int res=1)
{
	for(int now=x;y;y>>=1)
	{
		if(y&1)
			res=(res*now)%mod;
		now=(now*now)%mod;
	}
	return res;
}
inline int calc(int len)
{
	int ans=qp(v,len*2ll);
	ans-=(v-1)*qp(v,len-1)%mod;
	return (ans%mod+mod)%mod;
}
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cl(),cin>>n>>m>>v;
		int fl=0;
		for(int i=1;i<=m;++i)
		{
			cin>>e[i].c>>e[i].d;
			if(mp.count(e[i].c)&&mp[e[i].c]!=e[i].d)
			{
				fl=-1;
				break;
			}
			mp[e[i].c]=e[i].d;
		}
		if(fl==-1)
		{
			cout<<0<<endl;
			continue;
		}
		sort(e+1,e+1+m,[](node x,node y){return x.c<y.c;});
		int now=e[1].c,ans=qp(v,2*(e[1].c-1));
		for(int i=2;i<=m;++i)
		{
			int len=e[i].c-now;
			now=e[i].c;
			if(!len)
				continue;
			ans=ans*calc(len)%mod;
		}
		ans=ans*qp(v,2*(n-e[m].c))%mod;
		cout<<ans<<endl;
	}
	return 0;
}
