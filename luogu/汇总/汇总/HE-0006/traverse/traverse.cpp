#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10,mod=1e9+7,inv2=(mod+1)/2;
vector<int> e[N];
int fac[N],ifac[N];
int op[N];
PII E[N];
int n,k;

int qmi(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		k>>=1;
		a=a*a%mod;
	}
	return res;
}

namespace Sub1//k=1
{
	int Dp(int u,int fa)
	{
		int f=1;
		int cnt=0;
		for(auto v:e[u])
		{
			if(v==fa) continue;
			f=f*Dp(v,u)%mod;
			cnt++;
		}
		if(cnt>=2) f=f*fac[cnt]%mod;
		return f;
	}
	void solve()
	{
		int a=E[op[1]].first,b=E[op[1]].second;
		int res=Dp(a,b)*Dp(b,a)%mod;
		cout<<res<<"\n";
	}
}

namespace Sub2//tree
{
	void solve()
	{
		cout<<"1\n";
		return;
	}
}

namespace Sub3//d1=n-1
{
	int C(int a,int b)
	{
		if(a<b) return 0;
		return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
	}
	void solve()
	{
		int res=k*fac[n-2]%mod;
		if(n>=3) res=(res-C(k,2)*fac[n-3]%mod+mod)%mod;
		cout<<res<<"\n";
	}
}

int type,T;

void solve()
{
	cin>>n>>k;
	for(int i=1,a,b;i<n;i++) cin>>a>>b,e[a].push_back(b),e[b].push_back(a),E[i]={a,b};
	for(int i=1;i<=k;i++) cin>>op[i];
	if(k==1) Sub1::solve();
	else if(type==18) Sub2::solve();
	else Sub3::solve();
	for(int i=1;i<=n;i++) e[i].clear();
}

void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=qmi(fac[n],mod-2);
	for(int i=n-1;i>=0;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
}

signed main()
{
//	system("fc .out traverse10.ans"),exit(0);
	
//	freopen("traverse10.in","r",stdin);
//	freopen(".out","w",stdout);
	
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	init(N-10);
	
	cin>>type>>T;
	for(int t=1;t<=T;t++) solve();
	
	return 0;
}
