#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+10,P=1e9+7;
int T,n,m,v,ans,a[N],b[N],c[N],d[N],to[N]; unordered_map<int,int>vis;
inline ll qpow(ll a,int b)
{ll res=1; for(;b;(a*=a)%=P,b>>=1) (b&1)&&((res*=a)%=P); return res;}
inline bool check()
{
	int flag=0; for(int i=1;i<n;i++)
	{
		if(flag&&to[i]&&flag!=to[i]) return 0;
		if(flag==a[i]) flag=b[i]; else flag=0;
		if(a[i]==to[i]) flag=b[i];
	}
	if(flag&&to[n]&&flag!=to[n]) return 0; return 1;
}
inline void dfs(int x)
{
	if(x==n) return ans+=check(),void();
	for(int i=1;i<=v;i++) for(int j=1;j<=v;j++)
		a[x]=i,b[x]=j,dfs(x+1);
}
signed main()
{
	freopen("assign.in","r",stdin),freopen("assign.out","w",stdout);
	// freopen("rand.out","r",stdin),freopen("a.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>T;T;T--,vis.clear())
	{
		cin>>n>>m>>v; bool flag=!(n==m),flag2=0;
		for(int i=1;i<=m;i++)
		{
			cin>>c[i]>>d[i],flag|=(c[i]!=i);
			if(vis.count(c[i])&&vis[c[i]]!=d[i]) flag2=1;
			vis[c[i]]=d[i];
		}
		if(flag2) {cout<<0<<endl; continue;}
		if(m==1) {cout<<qpow(v,(n-1)<<1)<<endl; continue;}
		if(!flag) {cout<<qpow(1ll*v*(v-1)%P+1,n-1)<<endl; continue;}
		memset(to,0,sizeof(to)); for(int i=1;i<=m;i++) to[c[i]]=d[i];
		for(int i=1;i<=n;i++) cerr<<i<<' '<<to[i]<<endl; cerr<<endl;
		dfs(1),cout<<ans<<endl,ans=0;
	}
}