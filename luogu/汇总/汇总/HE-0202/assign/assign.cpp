#include <iostream>
usin namespace std;
int t,n,m,c[100009],d[100009],x[100009],ans;
long long n,v
int main() {
	cin >> t;
	for(int i = 1;i <= t;i++) {
		cin >> n >> m >> v;
		for(int j = 1;j <= m;j++) {
			cin >> c[j] >> d[j];
			x[c[j]] = d[j];
		}
		for(int j = 1;j <= v;j++) {
			for(int k = 1;k <= v;k++) {
                if(k == x[j]) {
                    for(int w = 1;w <= v;w++) {
                        if(k != x[j+1]) {
                            ans++;
                        }
                    }
                }
			}
		}
	}
	cout << n*n - ans;
	return 0;
}
