#include<bits/stdc++.h>
#define fi first 
#define se second
#define eb emplace_back
#define pb push_back
#define pii std::pair<int,int>
typedef long long ll;
inline int read(){char ch=getchar();int x=0,f=1;for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+(ch^48);return f*x;}
inline void Max(int &x,int y){x=std::max(x,y);}
inline void Min(int &x,int y){x=std::min(x,y);}
const int N=1e5+10;
char s1[N],s2[N],t1[N],t2[N];
pii a[N],b[N];
int suma[N],sumb[N];
int numa0[N],numa1[N],numb0[N],numb1[N];
signed main(){
	freopen("edit.in","r",stdin);freopen("edit.out","w",stdout);
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	int T;std::cin>>T;while(T--){
		int n=0,ans=0;std::cin>>n;
		std::cin>>s1+1>>s2+1>>t1+1>>t2+1;
		int tot1=0,tot2=0;
		for(int i=1;i<=n;++i){
			suma[i]=suma[i-1]+s1[i]-'0';
			sumb[i]=sumb[i-1]+s2[i]-'0';
		}
		for(int i=1;i<=n;++i){
			if(t1[i]=='1'){
				if(t1[i-1]=='1')a[tot1].se=i;
				else a[++tot1]={i,i};
			}
			if(t2[i]=='1'){
				if(t2[i-1]=='1')b[tot2].se=i;
				else b[++tot2]={i,i};
			}
		}
		for(int i=1;i<=tot1;++i){
			int len=a[i].se-a[i].fi+1;
			numa1[i]=suma[a[i].se]-suma[a[i].fi-1];
			numa0[i]=len-numa1[i];
		}
		for(int i=1;i<=tot2;++i){
			int len=b[i].se-b[i].fi+1;
			numb1[i]=sumb[b[i].se]-sumb[b[i].fi-1];
			numb0[i]=len-numb1[i];
		}
		int p1=1,p2=1,na0=0,na1=0,nb0=0,nb1=0;
		for(int i=1;i<=n;++i){
			if(i==a[p1].fi)na0=numa0[p1],na1=numa1[p1++];
			if(i==b[p2].fi)nb0=numb0[p2],nb1=numb1[p2++];
			if(t1[i]=='0'&&t2[i]=='0')ans+=(s1[i]==s2[i]);
			if(t1[i]=='0'&&t2[i]=='1'){
				if(s1[i]=='1'){
					if(nb1)nb1--,ans++;
					else nb0--;
				}if(s1[i]=='0'){
					if(nb0)nb0--,ans++;
					else nb1--;
				}
			}
			if(t1[i]=='1'&&t2[i]=='0'){
				if(s2[i]=='1'){
					if(na1)na1--,ans++;
					else na0--;
				}if(s2[i]=='0'){
					if(na0)na0--,ans++;
					else na1--;
				}
			}
			if(t1[i]=='1'&&t2[i]=='1'){
				if(na0&&nb0){
					na0--,nb0--,ans++;
					continue;
				}
				if(na1&&nb1){
					na1--,nb1--,ans++;
					continue;
				}
				if(na0){
					na0--,nb1--;continue;
				}
				na1--,nb0--;continue;
			}
		}
		for(int i=1;i<=tot1;++i)a[i]={0,0};for(int i=1;i<=tot2;++i)b[i]={0,0};
		std::cout<<ans<<'\n';
	}
}
