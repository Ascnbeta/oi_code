#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
#define gc getchar()
#define rd read()
inline int read(){
	int x=0,f=0; char c=gc;
	for(;c<'0'||c>'9';c=gc) f|=(c=='-');
	for(;c>='0'&&c<='9';c=gc) x=(x<<1)+(x<<3)+(c^48);
	return f?-x:x;
}

int n,cs[2],ct[2],ans=0; char s[N],t[N],s0[N],t0[N];

void solve(){
	n=rd,cs[0]=cs[1]=ct[0]=ct[1]=ans=0; scanf("%s %s %s %s", s+1, t+1, s0+1, t0+1);
	for(int i=1;i<=n;++i){
		if(s0[i]=='1'&&(i==1||s0[i-1]=='0')){ for(int j=i;j<=n&&s0[j]!='0';++j) ++cs[s[j]-'0']; }
		if(t0[i]=='1'&&(i==1||t0[i-1]=='0')){ for(int j=i;j<=n&&t0[j]!='0';++j) ++ct[t[j]-'0']; }
		
		if(s0[i]=='0'&&t0[i]=='0') ans+=(s[i]==t[i]);
		else if(s0[i]=='1'&&t0[i]=='0'){
			if(cs[t[i]-'0']) ++ans,--cs[t[i]-'0'];
			else --cs[(t[i]-'0')^1];
		}	
		else if(s0[i]=='0'&&t0[i]=='1'){
			if(ct[s[i]-'0']) ++ans,--ct[s[i]-'0'];
			else --ct[(s[i]-'0')^1];
		}	
		else{
			if(cs[0]&&ct[0]) ++ans,--cs[0],--ct[0];
			else if(cs[1]&&ct[1]) ++ans,--cs[1],--ct[1];
			else if(cs[0]&&ct[1]) --cs[0],--ct[1];
			else --cs[1],--ct[0];			
		}	
	}
	printf("%d\n", ans);
}

int main(){
	
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	int T=rd;
	while(T--) solve();
	
	return 0;
}

/*
1
6
011101
111010
111010
101101

*/
