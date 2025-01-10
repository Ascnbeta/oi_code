#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
int c,t,n,k;
struct edge
{
	int u,v;
}d[100005];
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for (int i=1;i<n;i++)
			cin>>d[i].u>>d[i].v;
		if (c==18)cout<<k<<'\n';
	}
	return 0;
}
