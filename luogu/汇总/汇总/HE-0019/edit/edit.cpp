#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int n;
bool a[N],b[N],c[N],d[N];
int aa[2][N],bb[2][N];
int lsa[N],lsb[N];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		memset(aa,0,sizeof aa);
		memset(bb,0,sizeof bb);
		memset(lsa,0,sizeof lsa);
		memset(lsb,0,sizeof lsb);
		cin>>n;
		char cc;
		for(int i=1;i<=n;i++)cin>>cc,a[i]=(cc=='1');
		for(int i=1;i<=n;i++)cin>>cc,b[i]=(cc=='1');
		for(int i=1;i<=n;i++)cin>>cc,c[i]=(cc=='1');
		for(int i=1;i<=n;i++)cin>>cc,d[i]=(cc=='1');
		lsa[1]=1;
		for(int i=1;i<=n;i++)
		{
			if(c[i]&&c[i+1])lsa[i+1]=lsa[i];
			else lsa[i+1]=i+1;
			aa[a[i]][lsa[i]]++;
			// cerr<<"A"<<i<<' '<<lsa[i]<<'\n';
		}
		lsb[1]=1;
		for(int i=1;i<=n;i++)
		{
			if(d[i]&&d[i+1])lsb[i+1]=lsb[i];
			else lsb[i+1]=i+1;
			bb[b[i]][lsb[i]]++;
			// cerr<<"B"<<i<<' '<<lsb[i]<<'\n';
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			// cerr<<aa[0][lsa[i]]<<' '<<aa[1][lsa[i]]<<' '<<bb[0][lsb[i]]<<' '<<bb[1][lsb[i]]<<'\n';
			if(bb[0][lsb[i]]>0&&aa[0][lsa[i]]>0)
			{
				bb[0][lsb[i]]--,aa[0][lsa[i]]--;
				ans++;
			}
			else if(bb[1][lsb[i]]>0&&aa[1][lsa[i]]>0)
			{
				bb[1][lsb[i]]--,aa[1][lsa[i]]--;
				ans++;
			}
			else if(bb[0][lsb[i]]>0&&aa[1][lsa[1]]>0)
			{
				bb[0][lsb[i]]--,aa[1][lsa[i]]--;
			}
			else
			{
				bb[1][lsb[i]]--,aa[0][lsa[i]]--;
			}
		}
		cout<<ans<<'\n';

	}
	return 0;
}