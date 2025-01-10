#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main () {
	int T = 10;
	while (T--) {
		system("genP2572.exe > P2572.in");
		system("P2572.exe < P2572.in > st.out");
		system("P2572baoli.exe < P2572.in > cr.out");
		if (system("fc /w st.out cr.out")) {
			system("pause");
			return 0;
		}
	}
}