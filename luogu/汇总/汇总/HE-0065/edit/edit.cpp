#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+10;
int T,n,m,ans,cnt[2]; char s1[N],s2[N],t1[N],t2[N]; bool vis[N],yet[N];
struct aa {int l,r,op;}e[N<<1];
signed main()
{
	freopen("edit.in","r",stdin),freopen("edit.out","w",stdout);
	// freopen("rand.out","r",stdin),freopen("a.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>T;T;T--,m=ans=0)
	{
		cin>>n>>(s1+1)>>(s2+1)>>(t1+1)>>(t2+1),t1[n+1]=t2[n+1]='0';
		for(int i=1,last;i<=n+1;i++)
		{
			if(t1[i]=='1'&&t1[i-1]!=t1[i]) last=i;
			else if(t1[i]=='0'&&t1[i-1]=='1') e[++m]={last,i-1,0};
		}
		for(int i=1,last;i<=n+1;i++)
		{
			if(t2[i]=='1'&&t2[i-1]!=t2[i]) last=i;
			else if(t2[i]=='0'&&t2[i-1]=='1') e[++m]={last,i-1,1};
		}
		sort(e+1,e+1+m,[&](aa a,aa b){return a.l==b.l?a.r<b.r:a.l<b.l;});
		for(int i=1,op,l,r;i<=m;i++)
		{
			cnt[0]=cnt[1]=0,op=e[i].op,l=e[i].l,r=e[i].r;
			if(op==0)
			{
				for(int j=l;j<=r;j++) cnt[s1[j]-'0']++,vis[j]=1;
				for(int j=l;j<=r;j++)
				{
					if(s2[j]=='0')
					{
						if(cnt[0]) cnt[0]--,s1[j]='0',ans+=!yet[j],yet[j]=1;
						else s1[j]='1',ans-=yet[j],yet[j]=0;
					}
					else
					{
						if(cnt[1]) cnt[1]--,s1[j]='1',ans+=!yet[j],yet[j]=1;
						else s1[j]='0',ans-=yet[j],yet[j]=0;
					}
				}
			}
			else
			{
				for(int j=l;j<=r;j++) cnt[s2[j]-'0']++,vis[j]=1;
				for(int j=l;j<=r;j++)
				{
					if(s1[j]=='0')
					{
						if(cnt[0]) cnt[0]--,s2[j]='0',ans+=!yet[j],yet[j]=1;
						else s2[j]='1',ans-=yet[j],yet[j]=0;
					}
					else
					{
						if(cnt[1]) cnt[1]--,s2[j]='1',ans+=!yet[j],yet[j]=1;
						else s2[j]='0',ans-=yet[j],yet[j]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) if(!vis[i]) ans+=(s1[i]==s2[i]);
		cout<<ans<<endl; memset(vis,0,sizeof(vis)),memset(yet,0,sizeof(yet));
	}
}
