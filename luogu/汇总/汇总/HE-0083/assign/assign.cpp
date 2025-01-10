#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	long long int t,i;
	cin>>t;
	while(t--){
		long long int n,m,v,s=1,z=1;
		bool f1=false,f2=true;
		scanf("%d%d%d",&n,&m,&v);
		int c[100001],d;
		c[m+1]=0;
		int b[n+1];
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(i=1;i<=m;i++){
			scanf("%d%d",&c[i],&d);
			if(b[c[i]]&&d!=b[c[i]]){
				f1=true;
			}
			b[c[i]]=d; 
		}
		if(m!=n){
			f2=false;
		}
		if(f1){
			printf("0\n");
			continue;
		}
		if(f2){
			for(i=1;i<n;i++){
				s=s*(v*(v-1)+1);
				s%=1000000007;
			}
			printf("%d\n",s%(1000000007)); 
			continue;
		}else{
			sort(c+1,c+m+1);
			for(i=1;i<n;i++){
			 	if(i==c[z]){
			 		for(z=z+1;z<m;z++){
			 			if(c[z]!=c[z-1]){
			 				break;
						}
					}
			 		if(i+1==c[z]){
			 			s=s*(v*(v-1)+1);
						s%=1000000007;
					}else{
						s=s*(v*v);
						s%=1000000007;
					}
				}else{
					s=s*(v*v);
					s%=1000000007;
				}
			}
			printf("%d\n",s%(1000000007)); 
		}
	}
	return 0;
} 
