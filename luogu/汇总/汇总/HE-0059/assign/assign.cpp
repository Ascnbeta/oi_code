#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+10;
ll n,m,v;
ll T;
ll jc[N],inv[N];

int main() {
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	jc[1]=1,inv[1]=1;
	for(ll i=2;i<=N-10;i++) jc[i]=jc[i-1]*i%mod;
	for(ll i=2;i<=N-10;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(ll i=2;i<=N-10;i++) inv[i]=inv[i-1]*inv[i]%mod;
	while(T--) {
		cin>>n>>m>>v;
		if(n==m) {
			cout<<(v*(v-1)%mod+1)%mod*(n-1)%mod*inv[n-1]%mod<<'\n';
		}
	}
	return 0;
}
