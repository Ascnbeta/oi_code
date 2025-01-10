#include<bits/stdc++.h>
using namespace std;
#define N 1000000+5
#define ll long long 
const int MOD=1e9+7;
ll t,n,m,v,ans,cnt;
ll vis[N];
ll c[N],d[N];
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	while(t--){
		ans = 0;
		cnt = 0;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>c[i]>>d[i];
			if(!vis[d[i]]){
				vis[d[i]]=1;
				cnt++;
			}
		}

		ans=(1+(v)*(v-1))*(n)%MOD;
		cout<<ans<<endl;
	}
	return 0;
}
