#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mk make_pair
#define ps push_back
#define mo(x,y) (x+=y,x>=mod?x-=mod:0)
const int N=1e6+10,inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f,mod=1e9+7;
inline ll read(){
	char c=getchar(); ll x=0;bool f=0;
	while(!isdigit(c))f=c=='-'?1:0,c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?-x:x;
}
int t,n;
char s1[N],s2[N],s[N];
bool f1[N],f2[N];
int jia[N][2][2],cnt[2][2];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	// double ti=clock();
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	t=read();
	while(t--){
		n=read();
		scanf("%s%s",s1+1,s2+1);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
			f1[i]=s[i]^48;
		for(int i=1;i<=n;++i){
			jia[i][0][0]=jia[i][0][1]=0;
			if(f1[i]){
				int chu=i;
				++jia[chu][0][s1[i]^48];
				++i;
				while(i<=n&&f1[i]){
					jia[i][0][0]=jia[i][0][1]=0;
					++jia[chu][0][s1[i]^48];
					++i;
				}
				--i;
			}
		}
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
			f2[i]=s[i]^48;
		for(int i=1;i<=n;++i){
			jia[i][1][0]=jia[i][1][1]=0;
			if(f2[i]){
				int chu=i;
				++jia[chu][1][s2[i]^48];
				++i;
				while(i<=n&&f2[i]){
					jia[i][1][0]=jia[i][1][1]=0;
					++jia[chu][1][s2[i]^48];
					++i;
				}
				--i;
			}
		}
		int ans=0;
		cnt[0][0]=cnt[0][1]=cnt[1][0]=cnt[1][1]=0;
		for(int i=1;i<=n;++i){
			cnt[0][0]+=jia[i][0][0];cnt[0][1]+=jia[i][0][1];cnt[1][0]+=jia[i][1][0],cnt[1][1]+=jia[i][1][1];
			if(!f1[i]&&!f2[i]){
				ans+=s1[i]==s2[i];
				cnt[0][0]=cnt[0][1]=cnt[1][0]=cnt[1][1]=0;
			}
			else if(!f1[i]){
				if(cnt[1][s1[i]^48])--cnt[1][s1[i]^48],++ans;
				cnt[0][0]=cnt[0][1]=0;
			}
			else if(!f2[i]){
				if(cnt[0][s2[i]^48])--cnt[0][s2[i]^48],++ans;
				cnt[1][0]=cnt[1][1]=0;
			}
			else{
				if(cnt[0][0]&&cnt[1][0])--cnt[0][0],--cnt[1][0],++ans;
				else if(cnt[0][1]&&cnt[1][1])--cnt[0][1],--cnt[1][1],++ans;
			}
		}
		cout<<ans<<'\n';
	}
	// cout<<(clock()-ti)/1e6<<endl;
}