#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char a[N],b[N],c[N],d[N];
int f[N],F[N],x[N][5],y[N][5];
int find(int a){
	if(f[a]==a)return f[a];
	return f[a]=find(f[a]);
}
int Find(int a){
	if(F[a]==a)return F[a];
	return F[a]=Find(F[a]);
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	int T;cin>>T;
	while(T--){
		int n;scanf("%d",&n);
		scanf("%s%s%s%s",a+1,b+1,c+1,d+1);
		int ans=0;
		for(int q=1;q<=n;q++){
			F[q]=f[q]=q;
			x[q][0]=x[q][1]=0;
			y[q][0]=y[q][1]=0;
		}
		for(int q=1;q<=n;q++){
			if(c[q]=='1'&&c[q-1]=='1')f[q]=find(q-1);
			x[f[q]][a[q]-'0']++;
			if(d[q]=='1'&&d[q-1]=='1')F[q]=Find(q-1);
			y[F[q]][b[q]-'0']++;
		}
		for(int q=1;q<=n;q++){
			if(d[q]=='0'){
				if(x[f[q]][b[q]-'0']!=0){
					x[f[q]][b[q]-'0']--;
					y[F[q]][b[q]-'0']--;
					ans++;
				}
			}
			else if(c[q]=='0'){
				if(y[F[q]][a[q]-'0']!=0){
					y[F[q]][a[q]-'0']--;
					x[f[q]][a[q]-'0']--;
					ans++;
				}	
			}
			if(x[f[q]][1]!=0&&y[F[q]][1]!=0){
				x[f[q]][1]--;
				y[F[q]][1]--;
				ans++;
			}
			else if(x[f[q]][0]!=0&&y[F[q]][0]!=0){
				x[f[q]][0]--;
				y[F[q]][0]--;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
