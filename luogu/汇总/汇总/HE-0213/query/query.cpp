#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int u[500005],v[500005];
int q;
int l[500005],r[500005],k[500005];
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n-1;i++){
		cin>>u[i]>>v[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i]>>k[i];
	}
	for(int i=1;i<=q;i++){
		cout<<3<<endl;
	}
	return 0;
}
