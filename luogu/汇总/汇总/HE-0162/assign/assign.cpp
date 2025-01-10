#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mod=1e5+10;
int T;
int n,m,v;
int a[N],b[N];
int c[N],d[N];
int x[N];
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0;
		cin>>n>>m>>v;
		for (int i=1;i<=m;i++){
			cin>>c[i]>>d[i];
		}
		memset(x,0,sizeof(x));
		for (int i=1;i<=n;i++){
			x[c[i]]=d[i];
		}
		for (int i=1;i<=n;i++){
			int j=i+1;
			if(!x[i]&&!x[j]){
				ans+=v%mod;
			}
		}
		cout<<ans;
	}
	return 0;
}
