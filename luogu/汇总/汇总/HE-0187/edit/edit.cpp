#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
//freopen!!!!
int n,t;
/*
2
4
1111
0011
0011
0011
4
1111
0001
1110
0001
*/
int cnt;

bool aflag = true;

//记得初始化
int w1;
int w2;
bool cflag = true;
bool bflag = true;
int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int m = 1;m<=t;m++){
		string a;
		string b;
		string va;
		string vb;
		cin>>n;
		cin>>a;
		cin>>b;
		cin>>va;
		cin>>vb;
	//	cout<<"ok"<<endl;
		if(m == 1){	
			int ans1 = 0;
			int ans2 = 0; 
			for(int i = 0;i<n;i++){
				if(va[i]!=vb[i]) bflag = false;
				if(i>0){
					if(a[i]!=a[i-1]) {
						aflag = false;
					//	cout<<"false";
					}
				}
				if(va[i] == '0'){
					w1 = i;
					ans1++;
				}
				if(vb[i] == '0') {
					w2 - i;
					ans2++;
				}
			}
			if(ans1 != 1||ans2 != 1) cflag = false; 
		}
	//	cout<<"aglela"<<aflag<<endl;
		/*
		1
		6
		101011
		011010
		010011
		010011
		*/
		
		if(aflag){
		//	cout<<"success"<<endl;
			bflag = false;
			cflag = false;
			for(int i = 0;i<n;i++){
				if(a[i] == b[i]) cnt++;
			}
			cout<<cnt<<endl;
			cnt = 0;
			continue;
		}
		if(bflag){
			cout<<66666<<endl;
			int cnt1 = 0;
			int cnt2 = 0;
			int cnt3 = 0;
			int cnt4 = 0; 
			for(int i = 0;i<n;i++){
				if(va[i] == '1'){
					if(a[i] == '1') {
						cnt1++;
					}else{
						cnt2++;
					}
					if(b[i] == '1'){
						cnt3++;
					}else{
						cnt4++;
					}
				}else{
//					cout<<"cnt1"<<cnt1<<endl;
//					cout<<"cnt2"<<cnt2<<endl;
//					cout<<"cnt3"<<cnt3<<endl;
//					cout<<"cnt4"<<cnt4<<endl;
					if(a[i] == b[i]) {
						cnt++;
			//			cout<<00000<<endl;
					}
					cnt+=min(cnt1,cnt3);
					cnt+=min(cnt2,cnt4);
					cnt1 = 0;
					cnt2 = 0;
					cnt3 = 0;
					cnt4 = 0;
				}
				
			}
//			cout<<"cnt1"<<cnt1<<endl;
//			cout<<"cnt2"<<cnt2<<endl;
//			cout<<"cnt3"<<cnt3<<endl;
//			cout<<"cnt4"<<cnt4<<endl;
			cnt+=min(cnt1,cnt3);
			cnt+=min(cnt2,cnt4);
			cout<<cnt<<endl;
			cnt = 0;
			
			continue;
		}
		if(cflag){
//			if(w1 >= w2){
//				int cnt1 = 0;
//				int cnt2 = 0;
//				int cnt3 = 0;
//				int cnt4 = 0;
//				int cnt5 = 0;
//				int cnt6 = 0;
//				int cnt7 = 0;
//				int cnt8 = 0;
//				for(int i = 1;i<=w1;i++){
//					if(a[i] == '1') cnt1++;
//					else cnt2++;
//				}
//				for(int i = w1+1;i<=n;i++){
//					if(a[i] == '1')cnt3++;
//					else cnt4++;
//				}
//				for(int i  = 1;i<=w2;i++){
//					if(b[i] == '1') cnt5++;
//					else cnt6++;
//				}
//				for(int i = w2+1;i<=n;i++){
//					if(b[i] == '1') cnt7++;
//					else cnt8++;
//				}
//				if(cnt) 
//			}
			cout<<0<<endl;
			continue;
		}
	
		//cout<<cnt<<endl;
		cnt = 0;
		
		
	}
	
	

//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
