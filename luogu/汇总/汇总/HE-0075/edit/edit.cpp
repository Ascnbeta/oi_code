#include<bits/stdc++.h>
using namespace std;

const int N=2e5+107;
int n,ans;
bool vis[2][N];
char s[2][N],t[2][N];

int read()
{
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return f*s;
}

struct lmy
{
	int fa[N];
	int cnt[2][N];
	void clear(int n){for(int i=1;i<=n;i++)cnt[0][i]=cnt[1][0]=0;}
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int find(int x){return x==fa[x]?fa[x]:fa[x]=find(fa[x]);}
	void merge(int id,int x,int y)
	{
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy;
			cnt[0][fy]+=cnt[0][fx];
			cnt[1][fy]+=cnt[1][fx];
		}
	}
}q1,q2;

void prepare()
{
	q1.init(n),q2.init(n);
	for(int i=1;i<=n;i++) vis[1][i]=vis[0][i]=0;
	for(int i=1;i<=n;i++) 
	{
		q1.cnt[0][i]=(s[0][i]=='0');
		q1.cnt[1][i]=(s[0][i]=='1');
		q2.cnt[0][i]=(s[1][i]=='0');
		q2.cnt[1][i]=(s[1][i]=='1');
	}
	for(int i=1;i<=n;i++)
	{
		if(t[0][i]=='1'&&t[0][i-1]=='1') q1.merge(0,i,i-1);
		if(t[1][i]=='1'&&t[1][i-1]=='1') q2.merge(1,i,i-1);
		if(s[0][i]==s[1][i])
		{
			if(t[0][i]=='0'&&t[1][i]=='0')
			{
				vis[0][i]=vis[1][i]=1;
				ans++;
			}
		}
		if(s[0][i]!=s[1][i]) 
		{
			if(t[0][i]!=t[1][i]) 
			{
				if(t[0][i]=='1') vis[1][i]=1;
				if(t[1][i]=='1') vis[0][i]=1;
			}
		}
	}
}

void solve()
{
	for(int i=1;i<=n;i++)
	{
		if(vis[1][i]&&vis[0][i]) continue;
		if(vis[1][i])
		{
			int f=q1.find(i);
			int w=s[1][i]-'0';
			if(q1.cnt[w][f]) q1.cnt[w][f]--,ans++;
			vis[0][i]=1;
		}
		if(vis[0][i])
		{
			int f=q2.find(i);
			int w=s[0][i]-'0';
			if(q2.cnt[w][f]) q2.cnt[w][f]--,ans++;
			vis[1][i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[0][i]&&vis[1][i]) continue;
		int f1=q1.find(i),f2=q2.find(i);
		if(q1.cnt[0][f1]&&q2.cnt[0][f2])
		{
			q1.cnt[0][f1]--,q2.cnt[0][f2]--;
			ans++;
		}
		else if(q1.cnt[1][f1]&&q2.cnt[1][f2])
		{
			q1.cnt[1][f1]--,q2.cnt[1][f2]--;
			ans++;
		}
	}
}

int main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T=read();
	while(T--)
	{
		ans=0;
		n=read();
		scanf("%s %s",s[0]+1,s[1]+1);
		scanf("%s %s",t[0]+1,t[1]+1);
		prepare();
		solve();
		printf("%d\n",ans);
		q1.clear(n),q2.clear(n);
	}
}
