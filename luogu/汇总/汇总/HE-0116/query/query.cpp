#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0) {
		cout<<'-';
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1,u,v;i<=n-1;i++){
    	cin>>u>>v;
	}
	cin>>q;
	for(int i=1,l,r,k;i<=q;i++){
		cin>>l>>r>>k;
		cout<<r-k+1<<endl;
	}
	return 0;
}
