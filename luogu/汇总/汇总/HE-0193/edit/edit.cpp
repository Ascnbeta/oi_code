#include <iostream>
#include <cstring>
using namespace std;
int prefix0[100086] , prefix1[100086];bool vis[100086];
int main(){
	freopen("edit.in" , "r" , stdin);
	freopen("edit.out" , "w" , stdout);

	int t;cin >> t;
	for(int q = 1 ; q <= t ; ++q){
		int n;cin >> n;
		string s1 , s2 , s3 , s4;
		cin >> s1 >> s2 >> s3 >> s4;
		memset(prefix0 , 0 , sizeof(prefix0));
		memset(prefix1 , 0 , sizeof(prefix1));
		memset(vis , 0 , sizeof(vis));
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(s1[i -1] == '1'){
				++cnt1;
			}if(s1[i - 1] == '0'){
				++cnt2;
			}
		}
		if(cnt1 == n || cnt2 ==n){
			int num = 0;
			if(cnt1 == n){
				for(int i = 1 ; i <= n ; ++i){
					if(s2[i - 1] == '1')++num;
				}
				cout << num << endl;
			}
			if(cnt2 == n){
				for(int i = 1; i <= n ; ++i){
					if(s2[i - 1] == '0')++num;
				} 
				cout << num << endl;
			}
			continue;
		} 
		if(s3 == s4){
			int ans = 0 ,tmp = 1;
			for(int i= 0; i < n ; ++i){
				if(s4[i] == '0' || s3[i] == '0' ){
					if(s2[i] == s1[i]){
						++ans;vis[i] = true;
					} 
				
				}
					int num10 = 0 ,num11 = 0 , num21 = 0  , num20= 0;
					for(; i <= n ; ++i){
						if(s4[i] == '0' && !vis[i]){	
							if(s2[i] == s1[i])
							++ans;ans +=  min(num11 , num21) + min(num10 , num20);
							break;cerr << i << ' ';
						}
						if(!vis[i]){
						
						if(s1[i] == '0'){num10++;
						}	if(s1[i] == '1'){num11++;
						}	if(s2[i] == '0'){num20++;
						}	if(s2[i] == '1'){num21++;
						}
					}
						if(s4[i] == '0' && !vis[i]){	
							ans +=  min(num11 , num21) + min(num10 , num20);
						//	vis[i] = 1;
							break;
						}
					}
					
			}
			cout << ans << endl;
			continue;
		}
		for(int i = 1 ; i <= n ; ++i){
			if(i > 1 && s4[i - 2] == '0' && s2[i - 2] == s2[ i - 1] == '0'){
				prefix0[i] = 1;
			}else if(s2[i - 1] == '0'){
				prefix0[i] = prefix0[i - 1] + 1;
			}
		}
		
		for(int i = 1 ; i <= n ; ++i){
			if(i > 1 && s4[i - 2] == '0' && s2[i - 2] == s2[ i - 1] == '1'){
				prefix1[i] = 1;
			}else if(s2[i - 1] == '1'){
				prefix1[i] = prefix1[i - 1] + 1;
			}
		}
		int ans = 0;

		for(int i = 1 ; i <= n ; ++i){
			if(s1[i - 1] == '1'){
				int tmp = i;
				if(prefix1[i] == 0)continue;
				while(prefix1[tmp] != 0){
					++tmp;
					prefix1[tmp]--;
				}
				if(prefix1[tmp] < 0){continue;
				} 
				++ans;
			}
			if(s1[i - 1] == '0'){
				int tmp = i;
				if(prefix0[i] == 0)continue;
				while(prefix0[tmp] != 0){
					++tmp;
					prefix0[tmp]--;
				}
				if(prefix0[tmp] < 0){continue;
				} 
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
