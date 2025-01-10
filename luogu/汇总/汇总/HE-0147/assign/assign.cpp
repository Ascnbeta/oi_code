#include<bits/stdc++.h>
using namespace std;
long long t,a[100005];
const long long mod=1e9+7;
int main()
{
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout); 
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,m,v;
		cin>>n>>m>>v;
		for(int i=0;i<m;i++){
			int c,d;
			cin>>c>>d;
			a[c]=d;
		}
		if(m==n){
			cout<<"1"<<endl;
		} 
	}
	return 0;
}
