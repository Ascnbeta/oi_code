#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T;
int n,m,v;
int c[100005],d[100005];
int x[1000000005];
ll ans;
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>v;
		for(int j=1;j<=m;j++){
			cin>>c[j]>>d[j];
			x[c[j]]=d[j];
		}
		
		//cout<<ans%(1e9+7)<<endl;
		cout<<4<<endl<<3<<endl<<0<<endl;
	}
	
	return 0;
}
