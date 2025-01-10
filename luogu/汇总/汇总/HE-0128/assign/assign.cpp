#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e9+3;
const int M=1e9+7;long long ans=0;
map<long long,bool> a,b;
int main(){
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    int t;cin>>t;
    while(t--){
    	ans=0;
    	a.clear();
    	long long q;
        long long n,m,v;cin>>n>>m>>v;
            for(int i=1;i<=m;i++){
            ll x,y;cin>>x>>y;
            a[x]=1;
        }
        if(a[2]){
				q=(v+(v-1)*v)%M;
			}else{
				q=(v*v*2)%M;
			}
			ans+=q%M;
		for(int i=2;i<=n-1;i++){
			if(a[i+1]){
				q=(v+(v-1)*v*q/i)%M;
			}else{
				q=(v*v*2*q/i)%M;
			}
			ans=(ans+q)%M;
		}
		cout<<ans<<endl;
    }
   fclose(stdin);
    fclose(stdout);
return 0;
}/*
1
5 1 2
1 2
*/
