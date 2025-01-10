#include<bits/stdc++.h>
using namespace std;
const int md=1e9+7;
void inline add(int &x,int y)
{
	x+=y;
	if(x>=md) x-=md;
}
struct mat{
	int a[2][2];
	mat()
	{
		memset(a,0,sizeof(a));
	}
	mat operator*(const mat &x)const
	{
		mat ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					add(ans.a[i][j],1ll*a[i][k]*x.a[k][j]%md);
		return ans;
	}
};
struct vec{
	int a[2];
	vec(){
		memset(a,0,sizeof(a));
	}
	vec operator*(const mat &x)const
	{
		vec ans;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				add(ans.a[i],1ll*a[j]*x.a[j][i]%md);
		return ans;
	}
};
struct node{
	int pos,val;
}p[100005];
bool cmpp(node r1,node r2)
{
	return r1.pos<r2.pos;
}
mat ks(mat a,int b)
{
	mat res;
	for(int i=0;i<2;i++)
		res.a[i][i]=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int n,m,v;
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	mat a,b;
	while(T--)
	{
		cin>>n>>m>>v;
		a.a[0][0]=1ll*v*v%md,a.a[0][1]=0,a.a[1][0]=1ll*v*(v-1)%md,a.a[1][1]=v;
		b.a[0][0]=1ll*v*(v-1)%md,b.a[0][1]=v,b.a[1][0]=1ll*(v-1)%md,b.a[1][1]=1;
		bool flag=0,flag1=0;
		for(int i=1;i<=m;i++)
		{
			cin>>p[i].pos>>p[i].val;
			if(p[i].pos==1) flag=1;
			if(p[i].pos==n) flag1=1;
		}
		sort(p+1,p+1+m,cmpp);
		int lst=1;
		vec ans;
		if(flag) ans.a[0]=v-1,ans.a[1]=1;
		else ans.a[0]=v;
		bool flag2=0;
		for(int i=1;i<=m;i++)
		{
			if(p[i].pos==p[i-1].pos)
			{
				if(p[i].val!=p[i-1].val)
				{
					flag2=1;
					break;
				}
			}
			else
			{
				if(p[i].pos==1||p[i].pos==n) continue;
				ans=ans*ks(a,p[i].pos-lst-1);
				lst=p[i].pos;
				ans=ans*b;
			}
		}
		ans=ans*ks(a,n-lst-1);
		if(flag2)
		{
			cout<<0<<'\n';
			continue;
		}
		if(flag1)
			cout<<(1ll*ans.a[0]*v%md+ans.a[1])%md<<'\n';
		else
			cout<<(1ll*ans.a[0]*v%md+1ll*ans.a[1]*v%md)%md<<'\n';
	}
}
