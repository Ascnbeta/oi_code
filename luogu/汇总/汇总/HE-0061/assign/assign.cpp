#include<bits/stdc++.h>
using namespace std;
int f[10001][10001];
int a[10001];
int n,m,V;
int dfs(int nw,int v){
	if(nw>n)return 1;
	if(f[nw][v])return f[nw][v];
	if(a[nw+1]){
		f[nw][v]+=dfs(nw+1,a[nw]);
	}
	else for(int i=1;i<=V;i++){
		f[nw][v]+=dfs(nw+1,i);
	}
	return f[nw][v];
}
int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>V;
		for(int i=1;i<=m;i++){
			int c,d;
			cin>>c>>d;
			a[c]=d;
		}
		cout<<dfs(0,0)<<endl;
		for(int i=1;i<=n;i++)a[i]=0;
	}
}
