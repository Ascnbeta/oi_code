#include<iostream>
#include<cstdio>
#include<map>
#define True {printf("true\n");continue;}
#define False {printf("false\n");continue;}
#define Maybe {printf("maybe\n");continue;}
using namespace std;

int n,m,y[50005],r[50005],i,L,R;

map<int,int> mp;

int st[17][50005],log2[50005],mi[20];
void build_st()
{
	for(int i=2;i<=n;i++)
	  log2[i]=log2[i/2]+1;
	mi[0]=1;
	for(int i=1;i<20;i++)
	  mi[i]=mi[i-1]*2;
	for(int i=1;i<=16;i++)
	  for(int j=1;j<=n;j++)
	    st[i][j]=max(st[i-1][j],st[i-1][j+mi[i-1]]);
}
inline int ask(int l,int r)
{
	if(l>r)
	  return 0;
	return max(st[log2[r-l+1]][l],st[log2[r-l+1]][r-mi[log2[r-l+1]]+1]);
}

int fl(int x)//二分出第一个不大于x的位置
{
	int L=0,R=n+1,mid;
	while(L<R)
	{
		mid=(L+R+1)>>1;
		if(y[mid]<x)
		  L=mid;
		else R=mid-1;
	}
	return L;
}

char Getchar()
{
	return getchar();
	static char buff[1000000],*p,*end=p;
	if(p==end)
	  end=buff+fread(p=buff,1,1000000,stdin);
	return *(p++);
}
template<typename T>void read(T &x)
{
	static char rc;static int flag;
	x=0;rc=Getchar();flag=1;
	while(!isdigit(rc))
	  flag=(rc=='-'?-1:1),rc=Getchar();
	while(isdigit(rc))
	  x=x*10+rc-'0',rc=Getchar();
	x*=flag;
}

int main()
{
	read(n);
	for(i=1;i<=n;i++)
	  read(y[i]),read(r[i]),mp[y[i]]=i,st[0][i]=r[i];
	read(m);
	build_st();
	for(i=1;i<=m;i++)
	{
		read(L);read(R);
		if(mp.find(R)==mp.end())
		{
			if(mp.find(L)==mp.end())
			  Maybe;
			if(ask(mp[L]+1,fl(R))<r[mp[L]])
			  Maybe;
			False;
		}
		else if(mp.find(L)!=mp.end())
		{
			if(r[mp[L]]<r[mp[R]])
			  False;
			if(ask(mp[L]+1,mp[R]-1)>=r[mp[R]])
			  False;
			if(R-L==mp[R]-mp[L])
			  True;
			Maybe;
		}
		else
		{
			if(ask(fl(L)+1,mp[R]-1)>=r[mp[R]])
			  False;
			Maybe;
		}
	}
	return 0;
}