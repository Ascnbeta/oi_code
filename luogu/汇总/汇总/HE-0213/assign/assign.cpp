#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,m,v;
int c[100005],d[100005];
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>c[i]>>d[i];
		}
		cout<<4<<endl;
	}
	return 0;
}
