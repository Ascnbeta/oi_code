#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pa pair<int,int>
#define qr qr()
#define ve vector
#define fi first
#define se second
#define ps push_back
using namespace std;
const int N=3e5+200;
inline int qr{
	int x=0;char ch=getchar();bool f=0;
	while(ch>57||ch<48)f=(ch=='-')?1:0,ch=getchar();
	while(ch<=57&&ch>=48)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
int n,m,a[N];
char s1[N],s2[N],t1[N],t2[N];
bool T[N],f[N],vis[N],no[N];
ve<pa>tmp;
void init(){
	cin>>n;tmp.clear();
	cin>>s1>>s2>>t1>>t2;
	for(int i=0;i<n;++i)no[i]=0,vis[i]=0,f[i]=0,T[i]=0;
	for(int i=0;i<n;++i){
		f[i]=(t1[i]=='1'&&t2[i]=='1');
		vis[i]=(t1[i]=='1'||t2[i]=='1');
	}vis[n]=0;
	int L=0;
	int l=-1;
	for(int i=0;i<n;++i){
		if(f[i]){
			l=i-1;int r=i+1;
			if(i&&vis[l]){
				--l;
				while(l>=0&&(t1[l]==t1[l+1])&&(t2[l]==t2[l+1]))--l;
			}
			if(vis[r]){
				++r;
				while(r<n&&vis[r]&&(t1[r]==t1[r-1])&&(t2[r]==t2[r-1])||(t1[r]=='1'&&t2[r]=='1')){
					if(t1[r]=='1'&&t2[r]=='1')t1[r]=t1[r+1],t2[r]=t2[r+1];
					++r;
				}
			}
			for(int j=l+1;j<r;++j)t1[j]='0',t2[j]='0';i=r-1;
			tmp.ps({l+1,r-1});
		}
	}
	for(int i=0;i<n;++i){
		if(t1[i]=='1'){
			int r;
			for(r=i;r<n&&t1[r]=='1';++r);
			tmp.ps({i,r-1});
			i=r-1;
		}else if(t2[i]=='1'){
			int r;
			for(r=i;r<n&&t2[r]=='1';++r);
			tmp.ps({i,r-1});
			i=r-1;
		}
	}
//	for(int i=0;i<n;++i)cout<<T[i];cout<<endl;
//	for(int i=0;i<n;++i)cout<<f[i];cout<<endl;
	int cnt10=0,cnt11=0,cnt20=0,cnt21=0,ans=0;
//	for(int i=0;i<n;++i){
//			if(s1[i]=='0')++cnt10;
//			else ++cnt11;
//			if(s2[i]=='0')++cnt20;
//			else ++cnt21;
//	}
//	cout<<cnt10<<' '<<cnt11<<' '<<cnt20<<' '<<cnt21<<' '<<min(cnt20,cnt10)<<' '<<min(cnt11,cnt21)<<endl;
	cnt10=0,cnt11=0,cnt20=0,cnt21=0,ans=0;
//	cout<<ans<<endl;
	for(auto k:tmp){
		for(int i=k.fi;i<=k.se;++i){
			no[i]=1;
			if(s1[i]=='0')++cnt10;
			else ++cnt11;
			if(s2[i]=='0')++cnt20;
			else ++cnt21;
		}
//		cout<<k.fi<<' '<<k.se<<' '<<min(cnt20,cnt10)<<' '<<min(cnt11,cnt21)<<endl;
		ans+=min(cnt20,cnt10)+min(cnt11,cnt21);
		cnt10=0;cnt11=0;cnt20=0;cnt21=0;
	}
//	cout<<ans<<endl;
//	for(int i=0;i<n;++i)cout<<no[i];cout<<endl;
	for(int i=0;i<n;++i)if(!no[i])ans+=s1[i]==s2[i];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)
		init();
	return 0;
}
