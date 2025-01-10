#include<bits/stdc++.h>
#define int long long
const int P=1e9+7;
using namespace std;
struct limit{
	int c,d;
}num[10000];
int T;
int n,m,v;
int x[10000];
int flag=0;
int ans;
signed main(){
	freopen("assign.in","r",stdin);
 	freopen("assign.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&v);
		for(int i=1;i<=m;i++){
			scanf("%lld%lld",&num[i].c,&num[i].d);
			if(num[i].c!=i){
				flag=1;
			}
		}
		if(flag==0&&m==n){
			ans=v*(v-1)%P+1;
			int a=ans;
			for(int i=2;i<=n-1;i++){
				ans=ans*a%P;
			}
			cout<<ans;
		} 
		cout<<endl;
	}
	return 0;
}
