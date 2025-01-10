#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[N],t[N],x[N],y[N];

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T --){
		int n;
		cin>>n;
		cin>>(s + 1);
		cin>>(t + 1);
		cin>>(x + 1);
		cin>>(y + 1);
		int cntA0 = 0,cntA1 = 0,cntB0 = 0,cntB1 = 0;
		int rA = 0,rB = 0;
		int ans = 0;
		for(int i = 1;i <= n;++ i){
			if(x[i] == '1' && i > rA){
				for(int j = i;j <= n && x[j] == '1';++ j){
					if(s[j] == '1') cntA1 ++;
					else cntA0 ++;
					rA = j;
				}
			}
			else if(x[i] == '0'){
				if(s[i] == '1') cntA1 ++;
				else cntA0 ++;
			}
			if(y[i] == '1' && i > rB){
				for(int j = i;j <= n && y[j] == '1';++ j){
					if(t[j] == '1') cntB1 ++;
					else cntB0 ++;
					rB = j;
				}
			}
			else if(y[i] == '0'){
				if(t[i] == '1') cntB1 ++;
				else cntB0 ++;
			}
			if(cntA0 && cntB0){
				ans ++;
				cntA0 --;
				cntB0 --;
			}
			else if(cntA1 && cntB1){
				ans ++;
				cntA1 --;
				cntB1 --;
			}
			else if(cntA0 && cntB1){
				cntA0 --;
				cntB1 --;
			}
			else{
				cntA1 --;
				cntB0 --;
			}
		}
		cout<<ans<<"\n";
	}
}

/*

9:00 OK

*/
