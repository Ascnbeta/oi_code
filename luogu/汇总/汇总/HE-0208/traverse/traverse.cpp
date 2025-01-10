#include<bits/stdc++.h>
using namespace std;
int t,c,n,k,i,j;
const long long N=1e5+10;
long long u[N],v[N],e[N];
int main()
{
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n>>k;
	}
	for(i=1;i<=n-1;i++)
	{
		cin>>u[i]>>v[i];
	}
	for(i=1;i<=k;i++)
	{
		cin>>e[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
