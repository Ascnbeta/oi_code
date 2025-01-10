#include<bits/stdc++.h>
using namespace std;
int ans[11],m,n,a,b,t,x[100010],y[100010],x1[100010],ya[100010],xx,yy;
bool w1[100010],w2[100010],bu1[100010],bu2[100010]; 
int num1(int lx,int ly){
	int ccf;
	for(int i=lx;i<ly;i++) if(w1[i]==1) ccf++;
	return ccf;
}
int num2(int lx,int ly){
	int ccf;
	for(int i=lx;i<ly;i++) if(w2[i]==1) ccf++;
	return ccf;
}
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++) {
		cin>>n;
		for(int j=0;j<n;j++) cin>>w1[j];
		for(int j=0;j<n;j++) cin>>w2[j];
		for(int j=0;j<n;j++) cin>>bu1[j];
		for(int j=0;j<n;j++) cin>>bu2[j];
		for(int j=0;j<n;j++){
			if(bu1[j]==0){
				x[a+xx]=num1(x1[a+xx-1],j);
				x1[a+xx]=j;
				a++;
			} 
			if(bu2[j]==0){
				y[b+yy]=num2(ya[b+yy-1],j);
				ya[b+yy]=j;
				b++;
			}
			if(a&&b){
				if(x1[a+xx]>=ya[b+yy]){
					for(int r=0;r<b;r++){
						if(x[a+xx]<y[r+yy]){
							y[r+yy]-=x[a+xx];
							x[a+xx]=0;
							ans[i]+=ya[r+yy-1]-x1[a+xx];
							break;
						} 
						x[a+xx]-=y[r+yy];
						ans[i]+=ya[r+yy-1]-ya[r+yy];
						y[r+yy]=0;
					} 
				}
				for(int r=0;r<a;r++){
					if(y[a+yy]<x[r+xx]){
						x[r+xx]-=y[b+yy];
						y[b+yy]=0;
						ans[i]+=x1[r+xx-1]-ya[b+yy];
						break;
					} 
					y[b+yy]-=x[r+xx];
					ans[i]+=x1[r+xx]-x1[r+xx-1];
					x[r+xx]=0;
				}  
				xx+=a;yy+=b;
				a=0;b=0;
			} 
		}
		memset(x,0,sizeof(x));memset(y,0,sizeof(y));memset(x1,0,sizeof(x1));memset(ya,0,sizeof(ya));
		xx=0;yy=0;
	}
	for(int i=0;i<t;i++) cout<<ans[i]/(n-1)<<endl;
	return 0;
} 
