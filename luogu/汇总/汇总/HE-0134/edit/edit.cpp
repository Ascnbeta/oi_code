#include<bits/stdc++.h>
using namespace std;
int x[100100], y[100100];
int main(){
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int cnt = 0;
		int n;
		cin >> n;
		string s1, s2, t1, t2;
		cin >> s1 >> s2 >> t1 >> t2;
		if(!s1.find('0') || !s1.find('1')){
			for(int i = 0; i < n; i++){
				if(s2[i] == s1[i]){
					cnt++;
				}
			}
			cout << cnt <<endl;
			continue;
		}//else if(t1 == t2){
			
//		}
		int a = 0, b = 0, c = 0, d = 0;
		for(int i = 0; i < n; i++){
			if(t1[i] == '0'){
				a++;
				c = i;
			}
			if(t2[i] == '0'){
				b++;
				d = i;
			}
		}
//		if(a == b && a == 1){
//			int w = 0, x = 0, y = 0, z = 0;
//			int e = 0, f = 0, g = 0, h = 0;
//			
//			for(int i = 0; i < c; i++){
//				if(s1[i] == '1'){
//					w++;
//				}
//				if(s1[i] == '0'){
//					x++;
//				}
//			}
//			for(int i = 0; i < d; i++){
//				if(s1[i] == '1'){
//					y++;
//				}
//				if(s1[i] == '0'){
//					z++;
//				}
//			}
//			for(int i = c + 1; i < n; i++){
//				if(s1[i] == '1'){
//					e++;
//				}
//				if(s1[i] == '0'){
//					f++;
//				}
//			}
//			for(int i = c + 1; i < n; i++){
//				if(s1[i] == '1'){
//					g++;
//				}
//				if(s1[i] == '0'){
//					h++;
//				}
//			}
//			if(c < d){
//				if(d - c == 1){
//					if(s1[c] == '0'){
//						x--;
//					}else{
//						w--;
//					}
//					if(e >= w){
//						e -= w;
//						w = 0;
//					}else{
//						w -= e;
//						e = 0;
//					}
//					if(f >= x){
//						f -= x;
//						x = 0;
//					}else{
//						x -= f;
//						f = 0;
//					}
//				}else{
//					
//				}
//			}
//		}
	}
	return 0;
}
