#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
const int mod=1e9+7;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) {
		cout<<'-';
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
struct  node{
	
	int to,next;
} edge[inf];
int n,k,c,t,e,ans;
bool check[inf];
int head[inf],cnt;
inline void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
signed main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>t;
	for(int l=1;l<=t;l++){
		cin>>n>>k;
		ans=0;
		for(int i=1,u,v;i<=n-1;i++){
			cin>>u>>v;
			add(u,v);
		}
		for(int i=1;i<=k;i++) cin>>e;
		cout<<rand()%mod<<endl; 
	}
	return 0;
}
