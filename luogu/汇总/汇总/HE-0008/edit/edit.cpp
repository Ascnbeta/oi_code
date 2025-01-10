#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define ll long long
using namespace std;
const int MAXN=1e5+10;
int T,n,c[2][2],ans;bool s[2][MAXN],b[2][MAXN];
inline void read(bool s[])
{
	string c;cin>>c;
	for(int i=0;i<n;++i)
		s[i]=(c[i]=='1');
}
inline void attend(int x,int &i)
	{for(;b[x][i];++i) ++c[x][s[x][i]];}
inline void work()
{
	cin>>n,ans=c[0][0]=c[0][1]=c[1][0]=c[1][1]=0;
	read(s[0]),read(s[1]),read(b[0]),read(b[1]);
	b[0][n]=b[1][n]=0;
	for(int x=0,y=1,i=0,j=0;i<n||j<n;)
	{
		attend(x,i),attend(y,j);
		if(i>j) swap(x,y),swap(i,j);
		int nowa=min(c[x][0],c[y][0]);
		int nowb=min(c[x][1],c[y][1]);
		ans+=nowa+nowb;
		c[x][0]-=nowa,c[y][0]-=nowa;
		c[x][1]-=nowb,c[y][1]-=nowb;
		if(c[x][0]) c[y][1]-=c[x][0];
		if(c[x][1]) c[y][0]-=c[x][1];
		c[x][0]=c[x][1]=0;
		if(i==j)
		{
			if(i==n) break;
			ans+=(s[0][i]==s[1][i]),++i,++j;
		}
		else if(c[y][s[x][i]])
			--c[y][s[x][i]],++ans,++i;
		else
			--c[y][s[x][i]^1],++i;
	}
	cout<<ans<<'\n';return ;
}
signed main()
{
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>T;while(T--) work();return 0;
}