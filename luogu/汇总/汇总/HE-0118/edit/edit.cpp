#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,bl[N],tot,ans;
int t[2][N],c[2];
string s1,s2,g;
queue<int>q;
inline void init()
{
	memset(t,0,sizeof(t));
	memset(bl,0,sizeof(bl));
	c[0]=c[1]=tot=ans=0;
	return ;
}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--)
	{
		init();
		cin>>n;
		cin>>s1>>s2>>g;
		g=" "+g;
		for(int i=1;i<=n;i++)
		{
			if(g[i]=='1')
			{
				tot+=(g[i]!=g[i-1]);
				t[s1[i-1]-'0'][tot]++;
			}
			else
				t[s1[i-1]-'0'][++tot]++;
			bl[i]=tot;
		}
		cin>>g;
		g=" "+g;
		for(int i=1;i<=n+1;i++)
		{
			if(i<=n&&g[i]=='1')
			{
				c[s2[i-1]-'0']++;
				q.push(bl[i]);
				continue;
			}
			while(!q.empty())
			{
				int x=q.front();
				q.pop();
				for(int j=0;j<=1;j++)
				{
					int res=(c[j]>0&&t[j][x]>0);
					ans+=res;
					c[j]-=res;
					t[j][x]-=res;
				}
			}
			c[0]=c[1]=0;
			if(i>n)
				continue;
			int res=(t[s2[i-1]-'0'][bl[i]]>0);
			ans+=res;
			t[s2[i-1]-'0'][bl[i]]-=res;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
