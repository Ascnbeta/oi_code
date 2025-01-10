#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n,u,v,q;
int l,r,k;
int a[N];
int ans;

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		a[u] = v;
		a[v] = u;
	}
	scanf("%d",&q);
	int b[q][3];
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&l,&r,&k);
		b[i][0] = l;
		b[i][1] = r;
		b[i][1] = k;
		
		cout<<r-k;
	}
}
