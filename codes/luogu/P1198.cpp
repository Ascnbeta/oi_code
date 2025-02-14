<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int m,d,len;
int main () {
	cin >> m >> d;
	while (m--) {
		char op;
		int x;
		cin >> op >> x;
		if (op == 'Q') {
			cout << query(len-x+1,len) << '\n';
		}else{
			
		}
	}
	return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int m,d,len;
int main () {
	cin >> m >> d;
	while (m--) {
		char op;
		int x;
		cin >> op >> x;
		if (op == 'Q') {
			cout << query(len-x+1,len) << '\n';
		}else{
			
		}
	}
	return 0;
>>>>>>> 801128a4a500b82867e2428b47a952cebc57da39
}