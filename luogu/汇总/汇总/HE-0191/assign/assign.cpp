#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,m,v,c[N],d[N];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&v);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&c[i],&d[i]);
			if(c[i]!=d[i]){
				printf("0");
				exit(0);
			}
		}
		printf("%d",n);
	}
	return 0;
}
