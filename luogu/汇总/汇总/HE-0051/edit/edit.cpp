#include <bits/stdc++.h>
#define ll long long
#define ts cout<<"*************"<<endl;
#define pb push_back
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N =2e5+5;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-f;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((x%10)|48);
}
inline void write(ll x,char p){
	write(x);putchar(p);
}
bool Mbe;
int n,fa1[N],fa2[N],l1[N],r1[N],l2[N],r2[N];
char s1[N],s2[N],t1[N],t2[N];
inline int find(int *fa,int x){
	return fa[x]==x?x:fa[x]=find(fa,fa[x]);
}
// inline bool check(int x,int y,int *l,int *r){
// 	return (l[x]<=l[y]&&l[y]<=r[x])||(l[x]<=r[y]&&r[y]<=r[x]);
// }
inline bool check(int x,int y){
	// if((l1[x]<=l2[y]&&l2[y]<=r1[x])||(l1[x]<=r2[y]&&r2[y]<=r1[x])){
	// 	if(t1[x]=='0'&&t1[y]=='0'&&t2[x]=='0'&&t2[y]=='0'){
			
	// 	}
	// }
	return (l1[x]<=l2[y]&&l2[y]<=r1[x])||(l1[x]<=r2[y]&&r2[y]<=r1[x]);
}
inline void merge(int *fa,int x,int y,int *l,int *r){
	x=find(fa,x);y=find(fa,y);
	if(x!=y){
		fa[x]=y;
		l[y]=min(l[y],l[x]);
		r[y]=max(r[y],r[x]);
	}
}
bool vis[N];int cnt,ans;
inline bool calc(int x,int y){
	if(x<1||x>n||y<1||y>n)return 0;
	if(check(find(fa1,x),find(fa1,y))||check(find(fa2,x),find(fa2,y))){
		// ts;
		cnt-=2;
		return 1;
	}
	return 0;
}
inline void solve(){
	n=read();
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	scanf("%s",t1+1);
	scanf("%s",t2+1);
	cnt=0,ans=n;
	std::vector<int> v10;
	set <int> v01;
	for(int i=1;i<=n;i++){
		vis[i-1]=0;
		fa1[i]=fa2[i]=i;l1[i]=r1[i]=l2[i]=r2[i]=i;

		if(s1[i]!=s2[i]){
			cnt++;
			if(t1[i]=='0'&&t2[i]=='0')continue;
			if(s1[i]=='1')v10.pb(i);
			else v01.insert(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(t1[i]=='0')continue;
		int r=i;
		while(t1[r+1]=='1'&&r+1<=n){
			merge(fa1,i,r+1,l1,r1);
			r++;
		}
		i=r;
	}
	for(int i=1;i<=n;i++){
		if(t2[i]=='0')continue;
		int r=i;
		while(t2[r+1]=='1'&&r+1<=n){
			merge(fa2,i,r+1,l2,r2);
			r++;
		}
		// cout<<i<<" "<<r<<endl;
		i=r;
	}	
	for(int i=0;i<v10.size();i++){
		// cout<<v[i-1]
		if(!v01.size())break;
		auto it=v01.upper_bound(v10[i]);
		if(it!=v01.begin()){
			it--;
			if(calc(v10[i],*it)){
				v01.erase(it);
				continue;
			}
			it++;
		}
		
		if(it!=v01.end()){
			// if(it==v01.end())continue;
			if(calc(v10[i],*it)){
				v01.erase(it);
				continue;
			}			
		}

	}
	write(ans-cnt,'\n');
}	
bool Med;
int main(){
	// file("a");
	file("edit");
	int T=read();
	while(T--){
		solve();
	}
	cerr<<(&Mbe-&Med)/1024.0/1024.0<<"MB "<<" "<<(double)clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}