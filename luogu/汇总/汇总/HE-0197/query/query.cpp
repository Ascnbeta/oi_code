#include<bits/stdc++.h>
using namespace std;

int T;
int ab[1000005];
int x[1000005];
int ans=0;
bool flag =0;
int n,m,v;//变量个数、一元限制个数,变量的取值上限
int c,d;
int modd = pow(10,9)+7;

int dfs(int ab_n,int flagto){
	int re=0;
	if(ab_n>n) return 1;
	else{
		
		if(flagto !=0){
			ab[ab_n] = flagto;
			re += dfs(ab_n+1,0);
			ab[ab_n] = 0;
		}
		else{
		
			if(x[ab_n] == 0){
				for(int i=1;i<=v;i++){
					ab[ab_n] = i;
					re += dfs(ab_n+1,0);
					ab[ab_n] = 0;
				}
			}
			else if(x[ab_n] != 0){
				if(x[ab_n+1] == 0){
					for(int i=1;i<=v;i++){
						ab[ab_n] = i;
						re += dfs(ab_n+1,0);
						ab[ab_n] = 0;
					}	
				}
				else if(x[ab_n+1] != 0){
					for(int i=1;i<=v;i++){
						ab[ab_n] = i;
						if(x[ab_n] == i){
							re += dfs(ab_n+1,i);
						}
						else{
							re += dfs(ab_n+1,0);
						}
						
						ab[ab_n] = 0;
					}	
				}
			}
		}
	}
	return re%modd;
}


int main(){
	freopen("assign2.in","r",stdin);
	freopen("assign2.out","w",stdout);
	
	scanf(" %d",&T);
	
	while(T--){
		//init
		memset(x,0,sizeof(x));
		flag =0;
		n=0,m=0,v=0;//变量个数、一元限制个数,变量的取值上限
		c=0,d=0;
		ans = 0;
		//
		scanf(" %d%d%d",&n,&m,&v);
		
		for(int i=0;i<m;i++){
			scanf(" %d %d",&c,&d);
			if(x[c] ==0) x[c] =d;
			else if(x[c] !=0 && x[c] != d) { ////delete
				flag =1;
				break;
			}
		}
		if(flag){
			printf("%d",ans);
			continue;
		}
//		for(int i=0;i<n;i++){
//			dfs(1);
//		}
		ans = dfs(1,0);
		//////////////////////////////////////
		printf("%d",ans);
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}




