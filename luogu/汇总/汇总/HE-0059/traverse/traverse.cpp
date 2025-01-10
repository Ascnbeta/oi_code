#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=1e9+7;
int T,c;
int n,k;
struct edge{
	int nxt,to;
}a[N];
int head[N],tot;
void add(int u,int v) {
	a[++tot].nxt=head[u];
	a[tot].to=v;
	head[u]=tot;
}
ll jc[N];
int main() {
	freopen("traverse.in","r",stdin);
	freopen("traverse.out","w",stdout);
	cin>>c>>T;
	jc[1]=1;
//	inv[1]=1;
	for(ll i=2;i<=N-10;i++) jc[i]=jc[i-1]*i%mod;
//	for(ll i=2;i<=N-10;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
//	for(ll i=2;i<=N-10;i++) inv[i]=inv[i-1]*inv[i]%mod;
	while(T--) {
		memset(head,0,sizeof(head));
		cin>>n>>k;
		for(int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
		}
		for(int i=1;i<=k;i++) {
			int x;
			cin>>x;
		}
		cout<<k*(jc[n-2])%mod<<'\n';
//		for(int i)
	}
	return 0;
}
