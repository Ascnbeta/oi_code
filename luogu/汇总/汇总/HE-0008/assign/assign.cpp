#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<unordered_map>
#define ll long long
using namespace std;
const int MAXN=1e5+10,mod=1e9+7;
int T,n,m,v,pos[MAXN],tot;ll ans;
unordered_map <int,int> vis;
struct node
{
	ll a[2][2];
	node operator * (const node &o)
	{
		node z;memset(z.a,0,sizeof(z.a));
		for(int i=0;i<2;++i) for(int j=0;j<2;++j)
			z.a[i][j]=(a[i][0]*o.a[0][j]+a[i][1]*o.a[1][j])%mod;
		return z;
	}
}f;
inline node ksm(node a,int b)
{
	node ans;memset(ans.a,0,sizeof(ans.a));
	ans.a[0][0]=ans.a[1][1]=1;
	for(;b;b>>=1,a=a*a)
		if(b&1) ans=ans*a;return ans;
}
inline int ksm(ll a,int b)
{
	ll ans=1;for(;b;b>>=1,a=a*a%mod)
		if(b&1) ans=ans*a%mod;return ans;
}
inline void work()
{
	cin>>n>>m>>v,vis.clear();
	ans=1,tot=pos[1]=0;bool flag=true;
	for(int i=1,x,y;i<=m;++i)
	{
		cin>>x>>y;
		if(!vis[x])
			vis[x]=y,pos[++tot]=x;
		else if(vis[x]!=y)
			flag=false;
	}
	if(!flag){cout<<"0\n";return ;}
	sort(pos+1,pos+1+tot);
	memset(f.a,0,sizeof(f.a));
	f.a[0][0]=v,f.a[0][1]=1ll*(v-1)*v%mod,f.a[1][1]=1ll*v*v%mod;
	for(int i=2;i<=tot;++i)
	{
		node cur=ksm(f,pos[i]-pos[i-1]-1);
		int f0=cur.a[0][0]*((1ll*(v-1)*v+1)%mod)%mod;
		int f1=cur.a[0][1]*((1ll*v*v)%mod)%mod;
		ans=ans*(f0+f1)%mod;
	}
	ans=ans*ksm(1ll*v*v%mod,n-1-(pos[tot]-pos[1]))%mod;
	cout<<ans<<'\n';return ;
}
signed main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>T;while(T--) work();return 0;
}