#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read()
{
	int x=0,c=getchar(),f=0;
	for(;c<'0'||c>'9';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int n,m,v;
int c[1<<20],d[1<<20];
int ans;

bool check(int a[],int nw)
{
	for(int i=1;i<=m;i++)
		if(c[i]<=nw&&a[c[i]]!=d[i]) return 0;
		
	return 1;
}

bool check2(int a[],int b[],int c[],int nw)
{
	for(int i=1;i<=nw;i++)
	if(i+1<=n&&a[i]==b[i]&&a[i+1]!=c[i+1]) return 0;
	
	return 1;
}

int dfs2(int a[],int b[],int c[],int p)
{
	if(!check2(a,b,c,p)) return 0;
	if(p>n) return 1;
	
	p++;
	int nw=0;
	for(int i=1;i<=v;i++)
	for(int j=1;j<=v;j++)
	{
		b[p]=i;
		c[p+1]=j;
		nw+=dfs2(a,b,c,p);
	}
	
	return nw;
}

void dfs(int a[],int p)
{
	if(!check(a,p)) return;
	if(p>n)
	{
		ans++;
//		int b[16]={},c[16]={};
//		ans+=dfs2(a,b,c,0);
		return;
	}
	p++;
	
	for(int i=1;i<=v;i++)
	{
		a[p]=i;
		dfs(a,p);
	}
	/*
	a[p]=0;
	dfs(a,p);
	a[p]=1;
	dfs(a,p);*/
}

void solve()
{
	ans=0;
	n=read();
	m=read();
	v=read();
	
	for(int i=1;i<=m;i++)
	{
		c[i]=read();
		d[i]=read();
	}
	
	int a[16]={};
	dfs(a,0);
	
	write(ans);
	putchar('\n');
}

signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	int t=read();
	while(t--) solve();
	
	return 0;
}

