#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,b;
queue<int> q;
bool ava = true;
int edt;
struct task{
	int t,d,time;
}ta[200005];
signed main () {
	cin >> n >> b;
	for (int i = 1; i <= n; i++) {
		int t,d;
		cin >> t >> d;
		ta[i].t = t,ta[i].d = d;
		while(!q.empty()) {
			if (t >= edt) {
				edt = edt + ta[q.front()].d;
                ta[q.front()].time = edt;
				q.pop();
				
			}else{
				break;
			}
		}
		if (q.empty()) {
			if (t >= edt) {
				ta[i].time = t + d;
				edt = t + d;
			}else{
				q.push(i);
			}
			continue;
		}
		if (q.size() < b) {
			q.push(i);
		}else{
			ta[i].time = -1;
		}
	}
	while(!q.empty()) {
		edt = edt + ta[q.front()].d;
        ta[q.front()].time = edt;
		q.pop();
	}
    for (int i = 1; i <= n; i++) {
        cout << ta[i].time << ' ';
    } 
	return 0;
}