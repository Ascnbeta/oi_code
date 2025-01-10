#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T;
int n;
char A[N],B[N],C[N],D[N];
int a[N],b[N],c[N],d[N];

void Solve(){
	//cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	scanf("%d",&n);
	scanf("%s",A+1);
	scanf("%s",B+1);
	scanf("%s",C+1);
	scanf("%s",D+1);
	for(int i=1;i<=n;i++) a[i]=A[i]-'0';
	for(int i=1;i<=n;i++) b[i]=B[i]-'0';
	for(int i=1;i<=n;i++) c[i]=C[i]-'0';
	for(int i=1;i<=n;i++) d[i]=D[i]-'0';
	int ans=0;
	int f0=0,f1=0,g0=0,g1=0;
	for(int i=1;i<=n;i++){
		if(c[i] && !c[i-1]){
			f0=f1=0;
			for(int j=i;j<=n;j++){
				if(!c[j]) break;
				if(a[j]) f1++;
				else f0++;
			}
		}
		if(!c[i]){
			f0=f1=0;
			if(a[i]) f1++;
			else f0++;
		}
		if(d[i] && !d[i-1]){
			g0=g1=0;
			for(int j=i;j<=n;j++){
				if(!d[j]) break;
				if(b[j]) g1++;
				else g0++;
			}
		}
		if(!d[i]){
			g0=g1=0;
			if(b[i]) g1++;
			else g0++;
		}
		if(f0 && g0) { ans++; f0--; g0--; }
		else if(f1 && g1) { ans++; f1--; g1--; } 
	}
	printf("%d\n",ans);
	//cerr<<clock()*1.0/CLOCKS_PER_SEC<<endl;
	//cerr<<endl;
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	scanf("%d",&T);
	while(T--) Solve();	
	return 0;
} 
