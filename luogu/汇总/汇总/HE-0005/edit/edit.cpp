#include"bits/stdc++.h"
using namespace std;
const int maxn = 1e5+10;
int T,n;
char a[maxn],b[maxn];
char A[maxn],B[maxn];
char Ak[maxn],Bk[maxn];
int Ca[2],Cb[2];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		queue<int>Qa,Qb;
		scanf("%d",&n);
		scanf("%s%s%s%s",a+1,b+1,A+1,B+1);
		for(int i=1;i<=n;i++)
			if(A[i]=='0')
				Qa.push(i);
		for(int i=1;i<=n;i++)
			if(B[i]=='0')
				Qb.push(i);
		Qa.push(n+1),Qb.push(n+1);
		Qa.push(n+2),Qb.push(n+2);
		int Ta=0,Tb=0;
		while(min(Qa.front(),Qb.front())<n+2){
			if(Qa.front()<Qb.front()){
				int X=Qa.front();
				Qa.pop(),Ca[0]=Ca[1]=0;
				for(int j=Ta+1;j<X;j++)
					if(a[j]=='1')Ca[1]++;
					else Ca[0]++;
				for(int j=Ta+1;j<X;j++)
					if(Bk[j]!=0){
						if(Ca[Bk[j]-'0'])Ca[Bk[j]-'0']--,Ak[j]=Bk[j];
						else Ca[1-Bk[j]+'0']--,Ak[j]='0'+'1'-Bk[j];
					}else{
						if(Ca[1])Ak[j]='1',Ca[1]--;
						else Ak[j]='0',Ca[0]--;
					}
				Ak[X]=a[X];
				Ta=X;
			}else{
				int X=Qb.front();
				Qb.pop(),Cb[0]=Cb[1]=0;
				for(int j=Tb+1;j<X;j++)
					if(b[j]=='1')Cb[1]++;
					else Cb[0]++;
				for(int j=Tb+1;j<X;j++)
					if(Ak[j]!=0){
						if(Cb[Ak[j]-'0'])Cb[Ak[j]-'0']--,Bk[j]=Ak[j];
						else Cb[1-Ak[j]+'0']--,Bk[j]='0'+'1'-Ak[j];
					}else{
						if(Cb[1])Bk[j]='1',Cb[1]--;
						else Bk[j]='0',Cb[0]--;
					}
				Bk[X]=b[X];
				Tb=X;
			}
		}
		int Ans=0;
		for(int i=1;i<=n;i++)
			Ans=Ans+(Ak[i]==Bk[i]);
		printf("%d\n",Ans);
		for(int i=1;i<=n;i++)
			Ak[i]=Bk[i]=a[i]=b[i]=A[i]=B[i]=0;
		Ca[0]=Ca[1]=Cb[0]=Cb[1]=0;
	}
} 
