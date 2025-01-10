#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pa pair<int,int>
#define qr qr()
#define ve vector
#define fi first
#define se second
#define ps push_back
using namespace std;
const int N=3e5+200,mod=1e9+7;
inline int qr{
	int x=0;char ch=getchar();bool f=0;
	while(ch>57||ch<48)f=(ch=='-')?1:0,ch=getchar();
	while(ch<=57&&ch>=48)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
int n,m,a[N];
struct node{
	int t,nx;
}e[N<<1];
int tot,h[N];
inline void add(int f,int t){
	e[++tot]={t,h[f]};
	h[f]=tot;
}
int all;
bool vis[N];
int staf[N],stat[N];
int sta[N],top;
map<int,map<int,int>>mp;
void init(){
	int cnt=0,cc=0;
	n=qr;m=qr;tot=0;
	for(int i=1;i<=n;++i)h[i]=0;
	for(int i=1,f,t;i<n;++i){
		f=qr;t=qr;
		add(f,t);add(t,f);
		mp[f][t]=++all;
		if(f+1==t)++cnt;
		if(t==i+1)++cc;
//		cout<<t<<' '<<i+1<<endl;
	}
	for(int i=1,f,t;i<=m;++i){
		f=qr;t=qr;
		staf[i]=f;stat[i]=t;
	}
	if(cnt==n-1)cout<<"1\n";
	else if(cc==n-1){
		int fac=1,bc=1;
		for(int i=1;i<n;++i)fac=1ll*fac*i%mod;
		for(int i=1;i<n-1;++i)bc=1ll*bc*i%mod;
		cout<<(1ll*m*fac-1ll*bc*m%mod*(m-1)%mod+mod)%mod<<'\n';
	}
}
int main(){

	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	
	int c=qr,t=qr;
	while(t--)
		init();
	return 0;
}

