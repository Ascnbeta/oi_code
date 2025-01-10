#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,u,v,q;
bool nn[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	long long maxn=-1;
	for(long long i=1;i<n;i++){
		cin>>u>>v;
		nn[u]=1;
		maxn=max(maxn,u);
	}
	cin>>q;
	for(long long i=1;i<=q;i++){
		long long l,r,k;
		cin>>l>>r>>k;
		for(long long j=r;j>=l;j--){
			if(nn[j]==1){
				cout<<j<<'\n';
				break;
			}
		}
	}
	return 0;
}
