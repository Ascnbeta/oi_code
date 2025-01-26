#include <bits/stdc++.h>
#define int __int128
using namespace std;
const int p1 = 399999959,p2 = 399999949;
int T;
int p = p1 * p2;
inline int Fread() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}
void print(int x) {
	if (x > 9) {
		print (x / 10);
	}
	putchar(x % 10 + '0');
}
void exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

signed main () {
    T = Fread();
    while (T--) {
        cout << "? ";
        print(p1);
        cout << endl;
        int x,i,j;
        x = Fread();
        if (x == -1) return 0;
        exgcd(p2,p1,i,j);
        int m1 = i;
        int ans = p2 * m1 * x % p;
        cout << "? ";
        print(p2);
        cout << endl;
        int y;
        y = Fread();
        exgcd(p1,p2,i,j);
        int n1 = i;
        ans = (ans + p1 * n1 * y % p) % p;
        cout << "! ";
        print((ans%p+p)%p);
        cout << endl;
    }
    return 0;
}