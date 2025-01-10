#include<bits/stdc++.h>
using namespace std;
int a,b,fa[1000000];
int l,r,k;
int jl[1000000][4];
int js[1000000];
int deep[1000000];
void find1(int x,int y){
	deep[x]=y;
	for(int i=1;i<=js[x];i++){
		if(fa[jl[x][i]]==0){
			fa[jl[x][i]]=x;
			find1(jl[x][i],y+1);
		}
	}
	return;
}
int find2(int x,int y){
	int mi=1000000000;
	for(int i=x;i<=y;i++){
		mi=min(mi,deep[x]);
		mi=min(mi,deep[y]);
	}
	return mi;
}
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>a;
	for(int i=1;i<a;i++){
		int x,y;
		cin>>x>>y;
		js[x]++;
		js[y]++;
		jl[x][js[x]]=y;
		jl[y][js[y]]=x;
	}
	fa[1]=1;
	deep[1]=1;
	find1(1,1);
	for(int i=1;i<=a;i++){
		cout<<deep[i]<<endl;
	}
	cin>>b;
	for(int i=1;i<=b;i++){
		int x,y,z;
		cin>>x>>y>>z;
		int ma=0;
		for(int j=x;j<=y;j++){
			for(int k=z;k<=y+1-j;k++){
				ma=max(ma,find2(j,j+k-1));
			}
		}
		cout<<ma<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
