#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e7+10;
const int mod = 1e9+7;
int t,m,n,v;

//×¢Òâ´óÐ¡ 
int ans;
int edge[maxn];
int vz[maxn];
/*
3
2 1 2
1 1
2 2 2
1 1
2 2
2 2 2
1 1
1 2

*/
signed main(){
	
//	freopen("assign.in","r",stdin);
//	freopen("assign.out","w",stdout);
	cin>>t;
	for(int u = 1;u<=t;u++){
		bool flag = false;
		cin>>n>>m>>v;
		for(int i = 1;i<=m;i++){
			int d,c;
			cin>>d>>c;
			if(edge[d] == 0) edge[d] = c;
			else {
				cout<<0<<endl;
				flag = true;
			}
			
			
		}
		if(flag) continue; 
		for(int i = 1;i<=v;i++){
			vz[i] = 1;
		}
		for(int deep  = 2;deep<=n;deep++){
			if(edge[deep] == 0){
				for(int i = 1;i<=v;i++){
					vz[i]*=v;
					vz[i] = vz[i]%mod;
				}
			}else{
				for(int i = 1;i<=v;i++){
					if(i!=edge[deep]){
						vz[i]*=(v-1);
						vz[i] = vz[i]%mod;
					}
				}
				vz[edge[deep]]*=v;
				vz[edge[deep]] = vz[edge[deep]]%mod;
			}
		}
		for(int i = 1;i<=v;i++){
			ans+=vz[i];
			ans = ans%mod;
		}
		cout<<ans<<endl;
//		for(int i = 1;i<=v;i++){
//			cout<<vz[i]<<" ";
//		}
		ans = 0;
	//	cout<<endl;
		for(int i = 1;i<=maxn;i++){
			edge[i] = 0;
		}
	}
	return 0;
} 
