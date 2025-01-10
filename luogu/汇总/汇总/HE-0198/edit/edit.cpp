#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int T;
int n;
bool g = true;//A
int ans;

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T --){
		ans = 0;
		char s[N],t[N];//s1,s2
 		char x[N],y[N];//t1,t2
		cin>>n;
		g = true;
		for(int i = 1;i <= n;i ++){
			cin>>s[i];
			if(s[i] != s[i-1] && i > 1) g = false;
		}
		for(int i = 1;i <= n;i ++){
			cin>>t[i];
		}
		if(g == true){
			for(int i = 1;i <= n;i ++){
				if(t[i] == s[i]) ans ++;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i = 1;i <= n;i ++){
			cin>>x[i];
		}
		for(int j = 1;j <= n;j ++){
			cin>>y[j];
		}
		if(x[2] == '0') x[1] = '0';
		if(x[n-1] == '0') x[n] = '0';
		if(y[2] == '0') y[1] = '0';
		if(y[n-1] == '0') y[n] = '0';
		for(int i = 2;i <= n-1;i ++){
			if(x[i] == '1'){
				if(x[i-1] == '0' && x[i+1] == '0') x[i] = '0';
			}
			if(y[i] == '0'){
				if(y[i-1] == '0' && y[i+1] == '0') y[i] = '0';
			}
		}
		int a = 0,b = 0,c = 0,d = 0;
		for(int i = 1;i <= n;i ++){
			if(x[i] == '0' && y[i] == '0'){
				if(s[i] == t[i]) ans ++;
				ans += min(a,c);
				ans += min(b,d);
				a = b = c = d = 0;
				continue;
			}
			if(x[i] != y[i] || (x[i] == '1' && y[i] == '1')){
				if(s[i] == '0') a ++;
				if(s[i] == '1') b ++;
				if(t[i] == '0') c ++;
				if(t[i] == '1') d ++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//QAQ
