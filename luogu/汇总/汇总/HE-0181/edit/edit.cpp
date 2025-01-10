#include<bits/stdc++.h>
using namespace std;
freopen("edip.in","r",stdin);
freopen("edip.out","r",stdout);
int t,m,ans=0,k,p;
int ko(m){	
	char a[10006],b[10006],c[10006],d[10006];
	for(int i=1;i<=m;i++){cin>>a[i];}
	for(int i=1;i<=m;i++){cin>>b[i];}
	for(int i=1;i<=m;i++){cin>>c[i];}
	for(int i=1;i<=m;i++){cin>>d[i];}
for(int i=1;i<=m;i++){
	k=a[i]-48;
	p=b[i]-48;
	if(k==p){
		ans++;
	}else{
		if(c[i]=='1'){
			ans++;
		}
		
	}
}
int main(){
	cin>>t>>m;
	for(int u=1;u<=t;u++){
    ko(m);
	cout<<ans;}
	
	return 0;
}
