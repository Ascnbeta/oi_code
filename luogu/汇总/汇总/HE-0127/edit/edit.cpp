#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
string a1, a2;
string f1,f2;
int n;
struct block{
	int l,r;
	int num0, num1;
	block(){
		l = r = num0 = num1 = 0;
	}
	inline void init(){
		l = r = num0 = num1 = 0;
	}
}bk1[maxn],bk2[maxn];
int cur1[maxn],cur2[maxn];
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	//ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		for(int i = 0;i < maxn;i++){
			bk1[i].init(),bk2[i].init();
		}
		
		int ans = 0;
		cin>>n;
		cin>>a1>>a2;
		cin>>f1>>f2;
		
		if(f1[0] == '1' && f1[1] == '0') f1[0] = '0';
		if(f1[n-1] == '1' && f1[n-2] == '0') f1[n-1] = '0';
		if(f2[0] == '1' && f2[1] == '0') f2[0] = '0';
		if(f2[n-1] == '1' && f2[n-2] == '0') f2[n-1] = '0';
		for(int i = 0;i < n-1;i++){
			if(f1[i] == '1' && f1[i-1] == '0' && f1[i+1] == '0') f1[i] = '0';
			if(f2[i] == '1' && f2[i-1] == '0' && f2[i+1] == '0') f2[i] = '0';
		}
		int cnt1 = 0,cnt2 = 0;
		bk1[cnt1].l = 0,bk2[cnt2].l = 0;
		for(int i = 0;i < n;i++){
			if(f1[i] == '1'){
				bk1[cnt1].r = i;
				if(a1[i] == '1') bk1[cnt1].num1++;
				else bk1[cnt1].num0++;
				cur1[i] = cnt1;
			}
			else{
				if(bk1[cnt1].r != 0) cnt1++;
				bk1[cnt1].l = i+1;
			}
			
			if(f2[i] == '1'){
				bk2[cnt2].r = i;
				if(a2[i] == '1') bk2[cnt2].num1++;
				else bk2[cnt2].num0++;
				cur2[i] = cnt2;
			}
			else{
				if(bk2[cnt2].r != 0) cnt2++;
				bk2[cnt2].l = i+1;
			}
		}
		
		for(int i = 0;i < n;i++){
			if(f1[i] == '0' && f2[i] == '1'){
				if(a1[i] == '0' && bk2[cur2[i]].num0)bk2[cur2[i]].num0--,ans++;
				if(a1[i] == '1' && bk2[cur2[i]].num1)bk2[cur2[i]].num1--,ans++;
			}
			if(f2[i] == '0' && f1[i] == '1'){
				if(a2[i] == '0' && bk1[cur1[i]].num0)bk1[cur1[i]].num0--,ans++;
				if(a2[i] == '1' && bk1[cur1[i]].num1)bk1[cur1[i]].num1--,ans++;
			}
		}
		
		for(int i = 0;i < n;i++){
			if(f1[i] == '1' && f2[i] == '1'){
				if(bk1[cur1[i]].num0 && bk2[cur2[i]].num0){
					bk1[cur1[i]].num0--;
					bk2[cur2[i]].num0--;
					ans++;
				}
				else if(bk1[cur1[i]].num1 && bk2[cur2[i]].num1){
					bk1[cur1[i]].num1--;
					bk2[cur2[i]].num1--;
					ans++;
				}
			}
			if(f1[i] == '0' && f2[i] == '0'){
				if(a1[i] == a2[i]) ans++;
			}
		}
		
		cout<<ans<<endl;
	}
}
