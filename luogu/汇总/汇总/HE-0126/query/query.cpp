#include<bits/stdc++.h>
#define int long long
using namespace std;
const int md=1e9+7;
int n;
int f[100005];
vector<int>e[100005];
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	int u,v;
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		{
			f[i]=v;
			continue;
		} 
		cin>>u>>v;
		e[u].push_back(v);
		f[i]=u;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<r-k<<"\n";
	}
}
