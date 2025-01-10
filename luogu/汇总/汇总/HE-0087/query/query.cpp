#include<bits/stdc++.h>
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

int n;
int dep[1<<21];
bool vis[1<<21];
int l[1<<21],r[1<<21];
vector<int> E[1<<21];

int st[1<<21][22];

inline int min(int x,int y) { return x<y?x:y; }
inline int max(int x,int y) { return x>y?x:y; }

void add(int u,int v)
{
	E[u].push_back(v);
}
int dfn[1<<21];
int logn[1<<21];
int tot;
int id[1<<21];

void dfs(int p,int deep)
{
	vis[p]=1;
	dep[p]=deep;
	dfn[p]=++tot;
	st[tot][0]=dfn[p];
	id[tot]=p;
	l[p]=tot;
	
	for(int i=0;i<E[p].size();i++)
	{
		int to=E[p][i];
		if(vis[to]) continue;
		
		dfs(to,deep+1);
		st[++tot][0]=dfn[p];
		id[tot]=p;
	}
	
	st[++tot][0]=dfn[p];
	id[tot]=p;
	r[p]=tot;
//	dfn[++tot]=p;
}

signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	for(int i=2;i<(1<<20);i++) logn[i]=logn[i>>1]+1;
	
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	memset(vis,0,sizeof(vis));
	
	for(int j=1;j<=logn[tot];j++)
	for(int i=1;i<=tot;i++)
	st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	
//	for(int j=0;j<logn[tot];j++)
//	for(int i=1;i<=tot;i++)
//	{
//		cout<<"l="<<i<<" r="<<i+(1<<j)-1<<" p="<<j<<" minn="<<st[i][j]<<" id="<<id[st[i][j]]<<"\n";
//	}
	
	int q=read();
	while(q--)
	{
		int L=read(),R=read(),k=read();
//		cout<<min(st[l][nw],st[r-(1<<nw)+1][nw])<<"\n";
	
		int maxn=-1;
		
//		priority_queue<pair<int,int> > ql,qr;
//		
//		for(int i=1;i<=k;i++)
//		{
//			int nw=L+i-1;
//			ql.push(make_pair(-l[nw],nw));
//			qr.push(make_pair(r[nw],nw));
//		}
		
		for(int i=L;i<=R-k+1;i++)
		{
			int ll=l[i],lr=r[i];
			
			for(int j=i+1;j<=i+k-1;j++)
			ll=min(ll,l[j]),lr=max(lr,r[j]);
//			while(ql.size()&&ql.top().second<i) ql.pop();
//			while(ql.size()&&qr.top().second<i) qr.pop();
			
//			ql.push(make_pair(-l[i],i));
//			qr.push(make_pair(r[i],i));
			
//			int ll=-ql.top().first;
//			int rl=qr.top().first;
			int len=lr-ll+1;
			int nw=logn[len];
			
	//		cout<<ll<<" "<<lr<<" ";
		//	cout<<rl<<" ";
	//		cout<<id[ll]<<" "<<id[lr]<<" "<<len<<" "<<" "<<id[min(st[ll][nw],st[lr-(1<<nw)+1][nw])]<<"\n";
		//
			
			maxn=max(maxn,dep[id[min(st[ll][nw],st[lr-(1<<nw)+1][nw])]]);
		//	int len=0;
		//	
		//	int nw=logn[len];
		//	maxn=max(maxn,dep[id[min(st[i][nw],st[i+k-(1<<nw)][nw])]]);
		}
		
		write(maxn);
		putchar('\n');
	}
	
	return 0;
}

