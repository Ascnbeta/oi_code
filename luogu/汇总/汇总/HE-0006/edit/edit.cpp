#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int b1[N],b2[N],c1,c2;
int cnt[N][2][2];
char s1[N],s2[N],t1[N],t2[N];
int n;
int T;

void solve()
{
	cin>>n;
	cin>>(s1+1);
	cin>>(s2+1);
	cin>>(t1+1);
	cin>>(t2+1);
	
	c1=1,c2=1;
	for(int i=1;i<=n;i++)
	{
		if(t1[i]=='1') 
		{
			b1[i]=c1;
			cnt[c1][0][s1[i]-'0']++;
		}
		else c1++;
	}
	for(int i=1;i<=n;i++)
	{
		if(t2[i]=='1') 
		{
			b2[i]=c2;
			cnt[c2][1][s2[i]-'0']++;
		}
		else c2++;
	}
	
//	for(int i=1;i<=n;i++) cout<<b1[i]<<" ";
//	cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<b2[i]<<" ";
//	cout<<"\n";
	
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(b1[i] && b2[i])
		{
			int x=b1[i],y=b2[i];
			if(cnt[x][0][0] && cnt[y][1][0]) res++,cnt[x][0][0]--,cnt[y][1][0]--;
			else if(cnt[x][0][1] && cnt[y][1][1]) res++,cnt[x][0][1]--,cnt[y][1][1]--;
		}
		if(b1[i] && !b2[i])
		{
			int x=b1[i],c=s2[i]-'0';
			if(cnt[x][0][c]) res++,cnt[x][0][c]--;
		}
		if(!b1[i] && b2[i])
		{
			int x=b2[i],c=s1[i]-'0';
			if(cnt[x][1][c]) res++,cnt[x][1][c]--;
		}
		if(!b1[i] && !b2[i])
		{
			int c1=s1[i]-'0',c2=s2[i]-'0';
			if(c1==c2) res++;
		}
	}
	
	cout<<res<<"\n";
	for(int i=1;i<=n;i++)
	{
		memset(cnt[i],0,sizeof cnt[i]);
		b1[i]=b2[i]=0;
	}
	c1=c2=0;
}

signed main()
{
//	system("fc .out edit2.ans"),exit(0);
	
//	freopen("edit2.in","r",stdin);
//	freopen(".out","w",stdout);
	
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--) solve();
	
	return 0;	
}

