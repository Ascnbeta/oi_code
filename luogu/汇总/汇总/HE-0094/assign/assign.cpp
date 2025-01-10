#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long t,n,m,v,ans;
struct cd
{
	int c,d;
}a[100005];
bool cmd(cd A,cd B)
{
	return A.c<B.c;
}
bool f[100005];
int c[100005];
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>v;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		bool flag=true;
		for (int i=1;i<=m;i++)
		{
			cin>>a[i].c>>a[i].d;
			if(a[i].d!=1)flag=false;
		}
		if(n==m)
		{
			ans=1;
			sort(a+1,a+m+1,cmd);
			for (int i=1;i<=m;i++)
				if(a[i].c==a[i+1].c&&a[i].d!=a[i+1].d)f[i]=f[i+1]=1;
			for (int i=1;i<=m;i++)
			{
				if(a[i].c==n)continue;
				if (a[i].c==a[i+1].c&&a[i].d==a[i+1].d) ans=(ans+v*v)%mod;
				else if (!f[i])ans=(ans*(v*(v-1)+1))%mod;
			}
		}
		else
		{
			ans=1;
			sort(a+1,a+m+1,cmd);
			for (int i=1;i<=m;i++)
				if(a[i].c==a[i+1].c)f[i]=f[i+1]=1;
			for (int i=1;i<=m;i++)
			{
				if(a[i].c==n)continue;
				if (a[i].c==a[i+1].c&&a[i].d==a[i+1].d) ans=ans*(ans+v*v)%mod;
				else if (!f[i]&&a[i+1].c==a[i].c+1)ans=(ans*(v*(v-1)+1))%mod;
				else ans=ans*v*v%mod;
				if (i==1)
					for (int j=1;j<a[i].c;j++) ans=ans*v*v%mod;
				if (i==m) for (int j=a[i].c+1;j<n;j++)ans=ans*v*v%mod;
				if(i!=1&&i!=m)for (int j=a[i].c+1;j<a[i+1].c;j++)ans=ans*ans%mod;
			}
		}
		if(ans==1)cout<<0<<'\n';
		else cout<<(ans%mod+mod)%mod<<'\n';
	}
	return 0;
} 
