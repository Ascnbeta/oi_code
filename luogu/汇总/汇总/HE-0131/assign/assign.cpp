#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,v;
const int MAXN=1e4+10;
const long long MO=10e9+7;
int chec[MAXN][MAXN];
int num[MAXN];
int p1,p2;
int wer=1;
void csh(){
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			chec[i][j]=0;
		}
	}
}
void work(){
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			for(int k=1;k<=n;k++){
				if(num[k]==i){
					if(num[k+1]==j&&k+1<=n){
						chec[i][j]=1;
					}else if(num[k+1]!=j&&k+1<=n){
						chec[i][j]=0;
						break;
					}
				}else if(num[k]!=i&&k+1<=n){
					chec[i][j]=1;
				}
			}
		}
	}
}
int cont(){
	int res=0;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			if(chec[i][j]){
				res++;
			}
		}
	}
	return res%MO;
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	for(int ch=0;ch<T;ch++){
		scanf("%d%d%d",&n,&m,&v);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&p1,&p2);
			if(num[p1]==0){
			num[p1]=p2;
		}else{
			wer=0;
			cout<<0;
			break;
		}
		}
		csh();
		work();
		memset(num,0,sizeof num);
		if(wer==1){
			cout<<cont();
		}
		wer=1;
	}
	return 0;
}
