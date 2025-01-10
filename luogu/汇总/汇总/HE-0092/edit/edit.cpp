#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+10;

int n,q;
char s[2][N];
char t[2][N];

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void print(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar(x%10+'0');
}

void solve(){
	n=read();
	cin>>s[0];
	cin>>s[1];
	cin>>t[0];
	cin>>t[1];
	int x=0,y=0;
	int ans=n;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(t[cnt][i]=='0'&&t[1-cnt][i]=='0'){
			ans-=abs(x);
			x=0;
			if(s[cnt][i]!=s[1-cnt][i])ans--;
			continue;
		}
		if(x>0&&s[cnt][i]=='0'&&t[cnt][i]=='1'){
			x--;
			s[cnt][i]='1';
		}
		if(x<0&&s[cnt][i]=='1'&&t[cnt][i]=='1'){
			x++;
			s[cnt][i]='0';
		}
		
		if(s[cnt][i]!=s[1-cnt][i]){
			if(s[cnt][i]=='0'){
				x--;
			}
			else{
				x++;
			}
		}
		if(t[1-cnt][i]=='0'&&x==0){
			cnt=1-cnt;
			x=-x;
		}
		if(t[cnt][i+1]=='0'){
			y++;
			cnt=1-cnt;
			x=-x;
			if(y==2){
				y-=2;
				ans-=abs(x);
				x=0;
			}
		}
//		cout<<n-ans<<' '<<x<<"\n";
	}
	print(ans-abs(x));
	cout<<"\n";
}

signed main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	q=read();
	while(q--)solve();
	return 0;
}
/*
1
6
011101
111010
111010
101101
1
5
10011
01100
11011
11101
*/
