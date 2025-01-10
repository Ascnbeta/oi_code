#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e5+107;
const int mod=1e9+7;
int n,m,v;
int c[N],d[N];

int read()
{
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}

int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		b=b>>1;
		a=a*a%mod;
	}
	return ans;
}

int ans,tmp[20],a[20],b[20];
int query()
{
	for(int i=1;i<=n;i++) a[i]=b[i];
	for(int i=1;i<=n-1;i++)
	{
		if(tmp[i]==1)
		{
			if(a[i]==0) continue;
			if(a[i]==1)
			{
				if(a[i+1]==0) a[i+1]=1;
				else if(a[i+1]!=1) return 0;
			}
		}
		if(tmp[i]==2)
		{
			if(a[i]==0) continue;
			if(a[i]==1)
			{
				if(a[i+1]==0) a[i+1]=2;
				else if(a[i+1]!=2) return 0;
			}
		}
		if(tmp[i]==3)
		{
			if(a[i]==0) continue;
			if(a[i]==2)
			{
				if(a[i+1]==0) a[i+1]=1;
				else if(a[i+1]!=1) return 0;
			} 
		}
		if(tmp[i]==4)
		{
			if(a[i]==0) continue;
			if(a[i]==2)
			{
				if(a[i+1]==0) a[i+1]=2;
				else if(a[i+1]!=2) return 0;
			} 
		}
	}
	return 1;
}

void dfs(int num)
{
	if(num==n-1)
	{
		(ans+=query())%=mod;
		return ;
	}
	for(int i=1;i<=4;i++)
	{
		tmp[num+1]=i;
		dfs(num+1);
		tmp[num+1]=0;
	}
}

int fac[100010],inv[100010];
void init()
{
	fac[0]=1;
	for(int i=1;i<=100000;i++) fac[i]=fac[i-1]*i%mod;
	inv[100000-1]=qpow(fac[100000-1],mod-2);
	for(int i=100000-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int C(int n,int m){return m>n?0:fac[n]*inv[m]%mod*inv[n-m]%mod;}

void baoli()
{
	int f1=0;
	for(int i=1;i<=m;i++)
	{
		if(c[i]!=i) f1=1;
	}
	if(n<=12&&m<=12&&v==2)
	{
		ans=0;
		int flag=0;
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=m;i++) 
		{
			if(b[c[i]]!=d[i]&&b[c[i]]!=0) flag=1;
			b[c[i]]=d[i];
		}
		if(flag) return printf("0\n"),void();
		dfs(0);
		printf("%lld\n",ans);
	}
	else if(m==1) printf("%lld\n",qpow(v,(2*n-2)));
	else if(m==n&&(!f1))
	{
		int ans=0;
		for(int i=1;i<=n-1;i++)
		{
			ans=(ans+qpow(v-1,i)*C(n-1,i)%mod*qpow(v*v-(v-1),n-1-i)%mod)%mod;
		}
		printf("%lld\n",(qpow(v,2*n-2)-ans+mod)%mod);
	}
}

signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T=read();
	init();
	while(T--)
	{
		n=read(),m=read(),v=read();
		for(int i=1;i<=m;i++) c[i]=read(),d[i]=read();
		
		baoli();
	}
}
