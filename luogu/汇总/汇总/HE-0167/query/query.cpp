#include<bits/stdc++.h>
using namespace std;
int n,pre[10001];
void root(int x,int y)
{
	return pre[x]=(pre[x]==x)?x:root(pre[x]);
}
int main()
{
	cin>>n;
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	for(int i=0;i<=n;i++)
	{
		cin>>u>>v;
		pre[u]=v;
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<(2*r-l+2-k);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
