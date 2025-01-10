#include<bits/stdc++.h>
using namespace std;
int x[100100], y[100100];
int main(){
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, m, v, b = 0;
		cin >> n >> m >> v;
		int x[2 * n] = {0}, y[2 * n] = {0};
		for(int i = 0; i <= n + 1; i++){
			x[i] = 0;
			y[i] = 0;
		}
		int cnt = v * v;
		long long sum = 1;
		for(int i = 0; i < m; i++){
			int c, d;
			cin >> c >> d;
//			cout << "y" <<endl;
			if(x[c] != 0 && x[c] != d){
				b++;
//				cout << x[c] << " " << 
			}else{
				x[c] = d;
			}
 		}
// 		cout <<"x" <<endl; 
 		if(b > 0){
 			cout << 0 <<endl;
 			b = 0;
 			continue;
		}
		for(int i = 1; i < n; i++){
			cnt = v * v;
			if(x[i] != 0){
				if(x[i + 1] != 0){
					cnt -= (v - 1);
				}
//				cout << ":" << x[i] << " " << x[i + 1] << " " <<endl;
				
			}
			sum *= cnt;
			sum %= 1000000007;
//			cout << sum <<endl;
		}
		cout << sum <<endl;
	}
	return 0;
}
