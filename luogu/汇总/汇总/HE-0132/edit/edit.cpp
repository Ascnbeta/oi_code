#include <bits/stdc++.h>
using namespace std;
const int MN=1e5;
int a[MN];
int b[MN];
int na[MN];
int nb[MN];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cf=1; cf<=T; cf++){
		int n;
		bool sam=true;
		bool B=true;
		scanf("%d",&n);
		int ans=0;
		int judge;
		scanf("%1d",&judge);
		a[1]=judge;		
		for(int i=2; i<=n; i++){scanf("%1d",&a[i]);if(a[i]!=judge) sam=false;}
		for(int i=1; i<=n; i++){scanf("%1d",&b[i]);}
		for(int i=1; i<=n; i++){scanf("%1d",&na[i]);}
		for(int i=1; i<=n; i++){scanf("%1d",&nb[i]);}
		for(int i=1; i<=n; i++){
			if(na[i]!=nb[i]){
				B=false;
			}
		}
		if(sam==true){
			for(int i=1; i<=n; i++){
				if(b[i]==judge){
					ans++;
				}
			}
		}
		if(B==true){
			int noa=0, nob=0;
			int nza=0, nzb=0;
			bool isthere=false;
			for(int i=1; i<=n; i++){
				if(na[i]==0){
					isthere=true;
				}
			}
			for(int i=1; i<=n; i++){
				if(na[i]==0){
					ans+=max(min(noa,nob),min(nza,nzb));
					noa=0;
					nob=0;
					nza=0;
					nzb=0;
					if(a[i]==b[i]){
						ans++;
					}
				}else{
					if(a[i]==1){
						noa++;
					}
					if(a[i]==0){
						nza++;
					}
					if(b[i]==1){
						nob++;
					}
					if(b[i]==0){
						nzb++;
					}
				}
			}
			if(na[n]==1){
				ans+=max(min(noa,nob),min(nza,nzb));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
