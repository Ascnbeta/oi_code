#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e5+5,mod = 1e9+7;
int T,n,m; LL v;
int p[N],tot;
unordered_map<int,int> a;
inline LL qpow(LL a,int b)
{
	LL res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}
struct Mat
{
	LL a[2][2];
	Mat(LL _x=0,LL _y=0,LL _z=0,LL _w=0) {a[0][0]=_x,a[0][1]=_y,a[1][0]=_z,a[1][1]=_w;}
	inline Mat operator * (const Mat &x) const
	{
		Mat res;
		for(int i=0;i<2;i++)
			for(int k=0;k<2;k++)
				for(int j=0;j<2;j++)
					res.a[i][j]=(res.a[i][j]+a[i][k]*x.a[k][j])%mod;
		return res;
	}
} X;
inline Mat Mqpow(Mat a,int b)
{
	Mat res={v*v%mod,(v*(v-1)+1)%mod,0,0}; b--;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a; b>>=1;
	}
	return res;
}
unordered_map<int,LL> mp;
inline LL cal(int x)
{
	if(mp[x]) return mp[x];
	return mp[x]=Mqpow(X,x).a[0][1];
}
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(p,0,sizeof(p));
		a.clear(); tot=0; mp.clear();
		scanf("%d%d%lld",&n,&m,&v);
		bool fl=0;
		for(int i=1;i<=m;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			if(!a[x]) a[x]=y, p[++tot]=x;
			if(a[x]&&a[x]!=y)  fl=1;
		}
		if(fl)
		{
			printf("0\n"); continue;
		}
		sort(p+1,p+1+tot);
		X={v*v%mod,(v-1)*v%mod,0,v};
		mp[0]=1; mp[1]=(v*(v-1)+1)%mod;
		LL ans=qpow(v*v%mod,(p[1]-1));
		for(int i=1;i<tot;i++)
		{
			ans=ans*cal(p[i+1]-p[i])%mod;
		}
		ans=ans*qpow(v*v%mod,n-p[tot])%mod;
		printf("%lld\n",ans);
	}

	return 0;
}