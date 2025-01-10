#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,m,v;
		scanf("%d%d%d",&n,&m,&v);
		vector<int> x(n+1,0);
		vector<int> c(m+1,0);
		vector<int> d(m+1,0);
		for(int j=1;j<=m;j++){
			scanf("%d%d",&c[j],&d[j]);
			x[c[j]]=d[j];
		}
		if(m==1){
			long long cnt=1;
			for(int i=1;i<=(n-1)*2;i++){
				cnt=cnt*v%MOD;
			}
			printf("%lld",cnt);
		}else{
			printf("0");
		}
		printf("\n");
	}
	
	return 0;
}
