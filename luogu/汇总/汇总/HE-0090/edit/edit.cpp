#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
bool A,B,C;//te xing 123
struct st{
	string p,q;
	int s[100010];
	int t[100010];
	int x,y;//1,0
}a,b;

int hz(int a){
	if(a<0){
		return 0;
	}
	return a;
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		A=B=C=1;
		memset(a.s,0,sizeof(a.s));
		memset(a.t,0,sizeof(a.t));
		cin>>n;
		cin>>a.p>>b.p>>a.q>>b.q;
		
		for(int i=1;i<=n;i++){
			a.s[i]=a.p[i-1]-'0';
			a.t[i]=a.q[i-1]-'0';
			b.s[i]=b.p[i-1]-'0';
			b.t[i]=b.q[i-1]-'0';
			if(i!=1&&a.s[i]!=a.s[i-1]) A=0;
			if(a.t[i]!=b.t[i]) B=0;
		}
		cout<<A<<' ';
		if(n<=10){
			ans=5;
		}
		if(A){
			for(int i=1;i<=n;i++){
				if(a.s[i]==b.s[i]) ans++;
			}
		}
		if(B&&!A){
			int j=0;
			for(int i=1;i<=n;i++){
				if(a.t[i]){
					j++;
					a.x+=a.s[i];
					a.y+=!a.s[i];
					b.x+=b.s[i];
					b.y+=!b.s[i];
				}
				
				if(!a.t[i]||i==n){
					if(a.s[i]==b.s[i]&&i!=n) ans++;
					ans+=j-abs(a.x-b.x);
					j=a.x=a.y=b.x=b.y=0;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

