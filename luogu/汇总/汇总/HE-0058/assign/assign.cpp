#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAXN=1e6+25;
int T,n,m,v;
bool vis[MAXN];
int num[MAXN],temp[MAXN];
int ans;
struct Node{
	int a,b;
}node[MAXN];
void dfs(int depth){
	if(depth==n){
		bool flag=0;
		for(int i=1;i<=n;i++) temp[i]=num[i];
		for(int i=1;i<n;i++){
			if(node[i].a==num[i]){
				if(vis[i+1]==true && node[i].b!=num[i+1]) {
					flag=1;
					break;
				}
				num[i+1]=node[i].b;
			}
		}
		for(int i=1;i<=n;i++) num[i]=temp[i];
		if(!flag){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=2;i++){
		for(int j=1;j<=2;j++){
			node[depth]={i,j};
			dfs(depth+1);
		}
	}
}
long long ksm(int v,long long n){
	if(n==0) return 1;
	if(n==1) return v;
	if(n%2==1) return ((ksm(v,n-1)%MOD)*v)%MOD;
	if(n%2==0) return ((ksm(v,n/2)%MOD)*(ksm(v,n/2)%MOD))%MOD;
} 
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	
	
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&v);
		memset(vis,0,sizeof vis);
		memset(num,0,sizeof num);
		ans=0;
		bool f=0;
		for(int i=1;i<=m;i++){
			int c,d;scanf("%d%d",&c,&d);
			if(vis[c]==true && num[c]!=d){
				printf("%d\n",0);
				f=1;
				break;
			}
			num[c]=d;
			vis[c]=1;
		}
		if(f) continue;
		if(v<=2){
			dfs(1);
			printf("%d\n",ans);
		}else if(m==1){
			if(n<=100000){
				long long tot=1;
				for(int p=1;p<=2*n-2;p++){
					tot*=v;
					tot%=MOD;
				}
				printf("%lld\n",tot);				
			}else{
				long long tot=ksm(v,2*n-2);
				printf("%lld\n",tot);
			}
		}else if(m==0){
			if(n<=100000){
				long long tot=1;
				for(int p=1;p<=2*n;p++){
					tot*=v;
					tot%=MOD;					
				}
				printf("%lld\n",tot);
			}else{
				long long tot=ksm(v,2*n);
				printf("%lld\n",tot);
			}
		}else if(m==n){
			long long tot=1;
			for(int i=1;i<n;i++){
				tot=tot*((v*v)%MOD-v+1)%MOD;
			}
			printf("%lld\n",tot);
		}
	}
	
	
	
	
	return 0;
}
