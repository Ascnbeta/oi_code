#include <bits/stdc++.h>
#include <string>

using namespace std;

const int mo = 1000000007;

int n,m,v;
int ve[100001];

bool non = false;

long long dfs(int p,int nx,int workas){
	if(p+1>nx)return 1;
	if(workas==4){
		return (((v-1)*v+1)%mo)*dfs(p+1,nx,0);
	}
	if(workas==1){
		return (((v-1)*v+1)%mo)*dfs(p+1,nx,0);
	}
	if(ve[p]==-1&&ve[p+1]==-1){
		if(p+2<=nx&&ve[p+2]!=-1)
		return ((v*v)%mo)*dfs(p+1,nx,4);
		else
		return ((v*v)%mo)*dfs(p+1,nx,0);
	}
	if(ve[p]!=-1&&ve[p+1]==-1){
		//cout<<ve[p+2]<<endl;
		if(p+2<=nx&&ve[p+2]!=-1)
			return((v*v - v)%mo)*dfs(p+1,nx,1) + (v%mo)*dfs(p+1,nx,4);
			//return (((v-1)*v+v)%mo)*dfs(p+1,nx,4);
		else
			return (((v-1)*v+v)%mo)*dfs(p+1,nx,0);
	}
	if(ve[p]==-1&&ve[p+1]!=-1){
		return ((v*v)%mo)*dfs(p+1,nx,0);
		//return (((v-1)%mo)*(v%mo)+v)*dfs(p+1,nx,0);
	}
	if(ve[p]!=-1&&ve[p+1]!=-1){
		return (((v-1)*v+1)%mo)*dfs(p+1,nx,0);
	}
}

void work(){
	
	cin>>n>>m>>v;
	non = false;
	memset(ve,-1,sizeof(ve));
	
	for(int i = 1;i<=m;i++){
		int mi,mj;
		cin>>mi>>mj;
		if(ve[mi]!=-1){
			non = true;
			break;
		}
		ve[mi] = mj;
		//cout<<"kk";
	}
	if(non)cout<<0<<endl;
	else
	cout<<dfs(1,n,0)<<endl;
}

int main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	int T;
	cin>>T;
	for(int i = 1;i<=T;i++){
		work();
	}
}
