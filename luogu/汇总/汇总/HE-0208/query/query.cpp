#include<bits/stdc++.h>
using namespace std;
int n,u,v,q,l,r,k,i,j;
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(i=1;i<=n-1;i++)
	{
		cin>>u>>v;
	}
	for(i=n+1;i>n;i--)
	{
		cin>>q;
	}
	for(i=1;i<=q;i++)
	{
		cin>>l>>r>>k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
