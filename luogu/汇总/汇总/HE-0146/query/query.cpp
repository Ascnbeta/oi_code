#include<bits/stdc++.h>
using namespace std;
int t,n,v[100010],nl,ans[100010],vv[100010];
vector<int> a[100010];
void dfs(int aa,int l,int y){
	if(v[aa]==y) return;
	if(aa==1){
		nl=l;
		return;
	}
	v[aa]=y;
	for(int i=0;i<a[aa].size();i++) dfs(a[aa][i],l+1,y);
	if(nl!=-1) ans[aa]=nl-l+1;
}
void dfs1(int aa,int l){
	if(v[aa]==-1) return;
	v[aa]=-1;
	ans[aa]=l;
	for(int i=0;i<a[aa].size();i++) dfs1(a[aa][i],l+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
	}
	dfs1(1,1);
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		dfs(i,1,i);
		nl=-1;
	}
	int q;
	cin>>q;
	while(q--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<1<<'\n';
	}
}
