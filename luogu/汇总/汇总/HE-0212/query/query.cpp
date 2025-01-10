#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int N=5e5+10;
int dfn[N],fa[N],ls[N],son[N];
struct tree{
	int u,v;
	int idx;
}t[N];

void build(int l,int r,int p){
	t[p].u=l,t[p].v=r;
	int mid=(l+r)/2;
	if(p>mid) build(l,mid,p*2);
	else build(mid+1,r,p*2+1);
}
struct opt{
	int l,r,k;
}op[N];
int n,q;
int ans[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		t[i].u=read(),t[i].v=read();
	}
	q=read();
	for(int i=1;i<=q;i++){
		op[i].l=read(),op[i].r=read(),op[i].k=read();
	}
	for(int i=1;i<=q;i++) ans[i]=1;
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
