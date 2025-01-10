#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int st1[100005],st2[100005],ed1[100005],ed2[100005];
bool vis[100005];
int ans=0,n;
void dfs(int x,int f)
{

}
int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s1>>s2>>t1>>t2;
		s1=' '+s1;s2=' '+s2;
		t1=' '+t1;t2=' '+t2;
		bool sol1=1;
		ans=0;
		for(int i=2;i<=n;i++)
		{
			if(s1[i]!=s1[i-1]) sol1=0;
		}
		if(sol1)
		{
			for(int i=1;i<=n;i++)
			{
				if(s2[i]==s1[i]) ans++;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(t1==t2)
		{
			int sm10=0,sm11=0,sm21=0,sm20=0;
			for(int i=1;i<=n;i++)
			{
				if(t1[i]=='0'||i==n)
				{
					if(s1[i]==s2[i]&&t1[i]==0)
					{
						ans++;
					}
					int w0=min(sm10,sm20);
					int w1=min(sm11,sm21);
					ans+=w0+w1;
					sm10=0;sm20=0;sm11=0;sm21=0;
				}
				else 
				{
					if(s1[i]=='0') sm10++;
					else sm11++;
					if(s2[i]==0) sm20++;
					else sm21++; 
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		else
		{
			cout<<n<<endl;
		}
	}	
	
}
