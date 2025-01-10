#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define itn long long 
const int oo = 100005;
int t,n;
char st[oo],sp[oo];
char et[oo],ep[oo];
main(void){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;while(t--){
		cin >> n;
		cin >>st+1;
		cin >>sp+1;
		cin >>et+1;
		cin >>ep+1;
		int flag = 0;
		for (int i=2;i<=n;++i){
			if (st[i]!=st[i-1]) flag = 1;
		}
		if (!flag){
			int cnt = 0;
			for (int i=1;i<=n;++i){
				if (sp[i]=='1'){
					cnt ++;
				}
			}
			if (st[1]=='1') cout << cnt << '\n';
			else cout << n-cnt << '\n';
			continue;
		}
		for (int i=1;i<=n;i++){
			if (et[i]!=ep[i]) flag = 0;
		}
		if (flag){
			int out = 0;
			int cnt1 = 0,cnt0 = 0;
			int cnt2 = 0,cnt4 = 0;
			for (int i=1;i<=n;i++){
				if (et[i]=='0'){
					if(st[i]==sp[i]) out ++;
					out += min(cnt1,cnt2);
					out += min(cnt0,cnt4);
					cnt1 = cnt0 = cnt2 = cnt4 = 0;
					continue ;
				}
				if (st[i]=='1')cnt1++;
				else cnt0++;
				if (sp[i]=='1')cnt2++;
				else cnt4++;
			}
			cout << out << '\n';
		}
	}
	exit (0);
}
