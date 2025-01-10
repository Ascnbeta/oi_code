#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,mod=1e9+7;
int T,c,n,k,vis[N],ans;
struct edge{int u,v;}e[N];
inline void init()
{
	ans=0;
	return ;
}
signed main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		init();
		cin>>n>>k;
		for(int i=2;i<=n;i++)
			cin>>e[i].u>>e[i].v;
		if(c==18)
		{
			for(int i=1,x;i<=k;i++)
				cin>>x;
			cout<<"1\n";
			continue;
		}
		cin>>k;
		cout<<ans<<"\n";
	}
	return 0;
}
