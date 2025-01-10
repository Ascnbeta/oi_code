#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10,N=5e5+10;
int n,drx,u,v;
struct edge{
	int to,next;
}e[M];
int head[N],q;
int dep[N];
void ahead(int u,int v){
	drx++;
	e[drx].next=head[u];
	head[u]=drx;
	e[drx].to=v;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		ahead(u,v);
		ahead(u,v);
	}
	dep[1]=1;
	int drx=dep[1];
	for(int i=head[1];i;i=e[i].next){
		dep[e[i].to]=drx+1;
		drx++;
	}
	int l,r;
	while(q--){
		scanf("%d%d",&l,&r);
		int maxx=0;
		for(int i=l;i<=r;i++){
			maxx=max(maxx,dep[i]);
		}
		printf("%d\n",maxx);
	}
	return 0;
}
