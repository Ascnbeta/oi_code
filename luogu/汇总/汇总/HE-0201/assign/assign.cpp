#include<bits/stdc++.h>
using namespace std;
int a,z,side;
long long dp,tx[100000]={},txx[10000]={};
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>a;
	while(a>0){
		long long n,m,v,c,d;
		z=1,side=1,dp=1;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>c>>d;
			if(c<=100000&&(tx[c]==0||tx[c]==d)){
				tx[c]=d;
			}
			else if(c>100000&&(tx[c-100000]==0||tx[c-100000]==d)){
				txx[c-100000]=d;
			}
			else if(c<=n){
				cout<<0<<endl;
				z=-1;
				break;
			}
		}
		if(z>0){
			while(side<=100000&&side<n){
				if(tx[side]==0||tx[side+1]==0||(tx[side]==0&&tx[side+1]==0)){
					dp*=v*v;
					if(dp>=1000000007){
						dp=dp%1000000007;
					}
					side++;
				}
				else{
					dp*=(v*v-v+1);
					if(dp>=1000000007){
						dp=dp%1000000007;
					}
					side++;
				}
			}
			side-=100000;
			while(side>10000&&side<n){
				if(txx[side]==0||txx[side+1]==0||(txx[side]==0&&txx[side+1]==0)){
					dp*=v*v;
					if(dp>=1000000007){
						dp=dp%1000000007;
					}
					side++;
				}
				else{
					dp*=(v*v-v+1);
					if(dp>=1000000007){
						dp=dp%1000000007;
					}
					side++;
				}
			}
			cout<<dp%1000000007;
		}
		a--;
	}

	return 0;
}

