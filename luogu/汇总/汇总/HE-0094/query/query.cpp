#include <bits/stdc++.h>
using namespace std;
int n,u,v,q,l,r,k,a[500010],deep[500010];
struct edge
{
	int x,y;
}dis[500010];
bool cmp(edge A,edge B)
{
	return A.x<B.x;
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	deep[1]=1;
	for (int i=1;i<n;i++)cin>>dis[i].x>>dis[i].y;
	sort(dis+1,dis+n,cmp);
	for (int i=1;i<n;i++)
		deep[dis[i].y]=i+1;
	
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		cin>>l>>r>>k;
		
	}
	return 0;
} 
