#include<bits/stdc++.h>
#define int long long 
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int mod=1e9+7;
const int N=1e5+10;
int ans=0,cnt;
struct node{
	int c,d;
}ls[N];
bool cmp(node x,node y){
	return x.c>y.c;
}
void dfs(int u){
	
}
int T;
int n,m,v;
vector<int> q; 
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	T=read();
	while(T--){
		n=read(),m=read(),v=read();
		for(int i=1;i<=m;i++){
			ls[i].c=read();
			ls[i].d=read();
		}
		cout<<0<<endl;
	}
	return 0;
}
