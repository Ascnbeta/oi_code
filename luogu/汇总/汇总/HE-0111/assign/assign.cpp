#include<bits/stdc++.h>
#define rd read()
#define int long long
#define pk(a) push_back(a)
#define epk(a) emplace_back(a)
#define mst(a,b) memset(a,b,sizeof(a))
#define fro(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rof(i,a,b) for(int i=a;i>=b;i--)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
const int N=1e5+5;
const int mod=1e9+7;

int read(){
	int x=0,w=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^'0');ch=getchar();}
	return x*w;
}

int mx(int a,int b){return a>b?a:b;}
int mn(int a,int b){return a<b?a:b;}

int n,m,v;
int c[N],d[N];

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

signed main(){

	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);

	int T=rd;
	while(T--){
		n=rd,m=rd,v=rd;
		fro(i,1,m){
			c[i]=rd,d[i]=rd;
		}
		int ans=1;
		fro(i,1,n)ans=(ans+qmi(v-1,i))%mod;
		printf("%lld\n",ans);
	}

	return 0;
}

