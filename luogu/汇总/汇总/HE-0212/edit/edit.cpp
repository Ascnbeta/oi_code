//20pts
#include<bits/stdc++.h>
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
const int N=1e5+10;
int T;//数据组数
int n;
char s1[N],s2[N],t1[N],t2[N];
int ans1=0,ans0=0;
bool flag;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) cin>>s1[i];
		for(int i=1;i<=n;i++) cin>>s2[i];
		for(int i=1;i<=n;i++) cin>>t1[i];
		for(int i=1;i<=n;i++) cin>>t2[i];
		for(int i=1;i<=n;i++){
			if(s2[i]=='1') ans1++;
			if(s2[i]=='0') ans0++;
		}
		for(int i=1;i<=n;i++){
			if(s1[i]=='1') flag=false;
			if(s1[i]=='0') flag=true;
		}
		if(flag) cout<<ans0<<endl;
		else cout<<ans1<<endl;
//		cout<<ans1<<endl<<ans0;
	}
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
