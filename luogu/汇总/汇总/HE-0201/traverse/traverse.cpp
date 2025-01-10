#include<bits/stdc++.h>
using namespace std;
int a,z,side,hud=0;
long long tx[100000]={},txx[10000]={},juh;
int Ou(int x,long long y){
	int t=10,tm=1,tk=0,zom[10000010]={},kom[10000010]={},bom[10000010]={},hom[11]={0,7,0,0,0,0,0,0,0,0,0,1},chi=y;
	while(x%t!=x){
		zom[tm]=x%t;
		kom[tm]=x%t;
		t=t*10;
		tm++;
	}
	while(chi>0){
		int pw=1,pm=1;
		for(int i=1;i<=tm;i++){
			bom[i]+=zom[i]*kom[pm]*pw;
		}
		chi--;
		pw=pw*10;
		pm++;
	}
	for(int i=1;i<=100000000;i++){
		if(bom[i]>=10){
			bom[i+1]+=bom[i]/10;
			bom[i]=bom[i]/10;
		}
	}
	while(bom[10]>0){
		for(int i=1;i<=10;i++){
			bom[i]-=hom[i];
		}
		for(int i=1;i<=100000000;i++){
			if(bom[i]<0){
				bom[i+1]--;
				bom[i]+=10;
			}
		}
	}
	int tu=1;
	for(int i=1;i<=10;i++){
		tk+=tu*bom[i];
		tu=tu*10;
	}
	return tk;
} 
int main(){
	//freopen("assign.in","r",stdin);
	//freopen("assign.out","w",stdout);
	cin>>a;
	while(a>0){
		long long n,m,v,c,d;
		z=1,side=1,hud=0,juh=1;
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
					side++;
				}
				else{
					hud++;
					side++;
				}
			}
			side-=100000;
			while(side>10000&&side<n){
				if(txx[side]==0||txx[side+1]==0||(txx[side]==0&&txx[side+1]==0)){
					side++;
				}
				else{
					hud++;
					side++;
				}
			}
			if(hud>0){
				int ku=1;
				for(int i=1;i<=n-1;i++){
					ku=ku*i;
				}
				cout<<ku*((v*v-v+1)*(v*v-v+1)+1)%1000000007;
			}
			else(hud==0){
				cout<<Ou(v,(2n-2));
			}
		}
		a--;
	}

	return 0;
}

