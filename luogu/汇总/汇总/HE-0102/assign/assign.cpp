#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10,p=1e9+7;
int n,m,T,v,c[N],d[N],a[N],b[N];
int qum(int a,int b){
	int ans=1;
	while(b){
		(b&1)&&(ans=ans*a%p);
		a=a*a%p;
		b>>=1;
	}return ans;
}
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++)cin>>c[i]>>d[i];
		int ans=1+v*(v-1)%p;
		ans=qum(ans,n-1);
		cout<<ans<<'\n';
	}
} 
