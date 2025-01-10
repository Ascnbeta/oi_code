#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=20,mod=1e9+7;
struct Matrix
{
	int a[2][2];
	void clear()
	{
		memset(a,0,sizeof a);
	}
	void make_I()
	{
		clear();
		for(int i=0;i<2;i++) a[i][i]=1;
	}
	Matrix operator*(const Matrix &B)const
	{
		Matrix res;res.clear();
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				res.a[i][j]=(a[i][0]*B.a[0][j]+a[i][1]*B.a[1][j])%mod;
			}
		}
		return res;
	}
	Matrix operator^(int k)
	{
		Matrix res,A=*this;res.make_I();
		while(k)
		{
			if(k&1) res=res*A;
			k>>=1;
			A=A*A;
		}
		return res;
	}
}B1,B2,F,B[M];
map<int,int> d;
int n,m,v;
int T;

void solve()
{
	bool Flg=true;
	cin>>n>>m>>v;
	for(int i=1,a,b;i<=m;i++)
	{
		cin>>a>>b;
		if(d.count(a)) Flg&=(d[a]==b);
		d[a]=b;
	}
	
	B1.clear(),B2.clear();
	B1.a[0][0]=v*v%mod,B1.a[0][1]=0;
	B1.a[1][0]=(v*v-v)%mod,B1.a[1][1]=v;
	
	B2.a[0][0]=(v*v-v)%mod,B2.a[0][1]=v;
	B2.a[1][0]=v-1,B2.a[1][1]=1;
	
	F.clear();
	F.a[0][0]=v-(d.count(1));
	F.a[0][1]=d.count(1);
	
	int last=1;
	for(auto it:d)
	{
		int x=it.first;
		if(x==1 || x==n) continue;
		int k=(x-last-1);
		if(k) F=F*(B1^k);
		F=F*B2;
		last=x;
	}
	int k=n-1-last;
	if(k) F=F*(B1^k);
	int res=0;
	if(!d.count(n))
	{
		res=F.a[0][1]*v%mod+F.a[0][0]*v%mod;
		res%=mod;
	}
	else
	{
		res=F.a[0][1]*1+F.a[0][0]*v%mod;
		res%=mod;
	}
	if(!Flg) res=0;
	cout<<res<<"\n";
	d.clear();
}

signed main()
{
//	system("fc .out assign3.ans"),exit(0);
	
//	freopen("assign3.in","r",stdin);
//	freopen(".out","w",stdout);
	
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);	
	
	cin>>T;
	while(T--) solve();
	
	return 0;
}
