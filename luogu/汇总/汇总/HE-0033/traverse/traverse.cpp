#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int N=1e5+10;
int head[N],tot;
struct node{
	int to,nxt;
}e[N*2];
void add(int a,int b){
	tot++;
	e[tot].to=b;
	e[tot].nxt=head[a];
	head[a]=tot;
}
long long val[N];
int in[N];
void init(){
//	cout<<"0";
	memset(e,0,sizeof e);
	tot=0;
	memset(head,0,sizeof head);
	memset(in,0,sizeof in);
}
int n,k;
const int MOD=1e9+7;
//int f[N];
void dfs(int x,int fa){
//	cout<<x<<"  "<<fa<<endl;
//	cout<<val[x]<<endl;
	int cnt=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		else cnt++;
	}
	bool ja=false;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
		if(in[y]==1&&cnt>1){
			val[x]+=val[y];
			if(!ja){
				val[x]-=1;
				ja=true;
			}
		}
		else val[x]=val[x]*val[y]%MOD;
		val[x]%=MOD;
//		cout<<x<<"  "<<val[x]<<endl;
	}
}
int a[N],b[N];
int ek[N];
void work1(){
	for(int i=1;i<=n;i++){
		val[i]=1;
	}
	int x=a[ek[1]],y=b[ek[1]];
	dfs(x,y),dfs(y,x);
	
	cout<<val[x]*val[y]%MOD<<endl;
}
// 1 1 4 1 1 2 2 3 2 4
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		init();
		n=read(),k=read();
		bool pan=false;
		for(int i=1;i<n;i++){
			a[i]=read(),b[i]=read();
			if(a[i]!=1) pan=true;
			add(a[i],b[i]),add(b[i],a[i]);
			in[a[i]]++,in[b[i]]++;
		}
		for(int i=1;i<=k;i++){
			ek[i]=read();
		}
		if(k==0){
			puts("0");
		}
		else if(k==1){
			work1();
		}else if(pan){
			puts("1");
		}else if(!pan){
			long long ans=1;
			for(int i=1;i<=k-1;i++){
				ans=ans*i%MOD;
			}
			cout<<ans<<endl;
		}	
	}
	return 0;
}
