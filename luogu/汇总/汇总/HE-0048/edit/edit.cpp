#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 1e5 + 10; 

string s_1 , s_2 , t_1 , t_2;
int T , n;
//int a1[N] , b1[N] , a2[N] , b2[N];
int cnt1 , cnt2 , tot1 , tot2;
int sum1[N] , sum2[N];
inline int find(int a , char s , string d){
	for (int i = a + 1 ; i <= n ; i++){
		if(s == '0' && d[i] == '0') return i;
		if(s == '1' && d[i] == '1') return i;	
	}
	return -1;
}

signed main(){
freopen("edit.in" , "r" , stdin);freopen("edit.out" , "w" , stdout);
	ios::sync_with_stdio(false) , cin.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		int ans = 0; cnt1 = cnt2 = tot1 = tot2 = 0;
		cin >> s_1 >> s_2 >> t_1 >> t_2;
		s_1 = ' ' + s_1 , s_2 = ' ' + s_2 , t_1 = ' ' + t_1 , t_2 = ' ' + t_2;
		for (int i = 1 ; i <= n ; i++){
			if(s_1[i] == '1') cnt1++; else cnt2++;
			if(s_2[i] == '1') tot1++; else tot2++;
			sum1[i] = sum1[i - 1] + (t_1[i] == '1');
			sum2[i] = sum2[i - 1] + (t_2[i] == '1');
		}
		
		if(cnt1 == n || cnt2 == n){
			if(cnt1 == n) cout << tot1 << "\n";
			else cout << tot2 << "\n";
			continue;
		}
		
		for (int i = 1 ; i <= n ; i++){
			if(s_1[i] == s_2[i]){ans++; continue;}	
			int p_1 = find(i , s_1[i] , s_2);
			int p_2 = find(i , s_2[i] , s_1);
			if(p_1 != -1){
//				cout << "p1: " << p_1 << '\n';
				if(sum2[p_1] - sum2[i - 1] == p_1 - i + 1){
					ans++;
					swap(s_2[i] , s_2[p_1]);
					continue;
				}
			}
			if(p_2 != -1){
//				cout << "p2: " << p_2 << '\n';
				if(sum1[p_2] - sum1[i - 1] == p_2 - i + 1){
					ans++;
					swap(s_1[i] , s_1[p_2]);
					continue;
				}
			}			
		}
//		cout << s_1 << ' ' << s_2 << "\n";
		cout << ans << "\n";
		for (int i = 0 ; i <= n ; i++){sum1[i] = sum2[i] = 0;}
	}
	return 0;
}
