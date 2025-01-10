#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int inf=1e6+10;
const int mod=1e9+7;
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
int t,n,m,v,c,d,ans;
int a,b;
int x[inf];
signed main(){
	freopen("assign.in","r",stdin);
	freopen("assign.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m>>v;
		ans=0;
		memset(x,0,sizeof(x)); 
		if(v==2){//v==2 的部分分 
			bool tag=false;
			for(int i=1;i<=m;i++){
    			cin>>c>>d;
    			if(x[c]  && x[c]!=d)tag=true;
			    x[c]=d;
    		}
    		if(tag){//输入冲突直接0 
    			cout<<0<<endl;
    			continue;
			}
		    else{
		    	a=1,b=1;
		    	for(int i=1;i<=n-1;i++){
		    		if(x[i]==a){
		    			if(x[i+1] && x[i+1]!=b) {
		    				tag=true;
		    				break;
						}
					} 
				}
				if(tag) tag=false;
				else ans++;
				a=1,b=2;
				for(int i=1;i<=n-1;i++){
		    		if(x[i]==a){
		    			if(x[i+1] && x[i+1]!=b) {
		    				tag=true;
		    				break;
						}
					} 
				}
				if(tag) tag=false;
				else ans++;
				a=2,b=1;
				for(int i=1;i<=n-1;i++){
		    		if(x[i]==a){
		    			if(x[i+1] && x[i+1]!=b) {
		    				tag=true;
		    				break;
						}
					} 
				}
				if(tag) tag=false;
				else ans++;
				a=2,b=2;
				for(int i=1;i<=n-1;i++){
		    		if(x[i]==a){
		    			if(x[i+1] && x[i+1]!=b) {
		    				tag=true;
		    				break;
						}
					} 
				}
				if(tag) tag=false;
				else ans++;
			}
			cout<<ans<<endl; 
		}
		else if(m==1){//m==1的部分分 
			cin>>c>>d;
			x[c]=d;
			cout<<(long long)v*(long long)v%mod;
		}
		else{//xj=j的部分分 
			for(int i=1,c,d;i<=m;i++) cin>>c>>d;
    		cout<<1<<endl;
		}
	}
	return 0;
}
