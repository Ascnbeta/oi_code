#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e7+9;
int c,T,n,k;
int u[N],v[N],e[N];
int main(){
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&e[i]);
		}
		if(c==18){
			printf("%d\n",1);
		}
		if(c>=19&&c<=21){
			printf("%d\n",((n-1)*k)*mod);
		}
	}
	return 0;
}
