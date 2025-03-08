#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,M;
int a,b,c;
int f[2300];
void init() {
	for (int i = 1; i <= 2250; i++) {
		f[i] = i*i;
	}
}
bool check(int x,int y,int z) {
	int delta = y*y-4*a*c;
	if (delta < 0) return false;
	return true;
}
int sq(int x) {
	int l = 1,r = M*M;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if (mid * mid <= x) {
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return l - 1;
}
int ms(int x) {
	int ret = 1;
	for (int i = 2250; i >= 1; i--) {
		if (x % f[i] == 0) ret *= i,x /= f[i];
	}
	return ret;
}
void print_frac(int z,int m) {
	bool f = false;
	if (z < 0) f = true,z *= -1;
	if (z == 0) {
		cout << 0 << '\n';
		return;
	}
	int g = __gcd(z,m);
	z /= g,m /= g;
	if (m == 1) {
		if (f) z *= -1;
		cout << z << '\n';
		return;
	}
    if (f) z *= -1;
	printf("%d/%d\n",z,m);
}
void print_sqrt (int xi,int sq,int z,int m) {
	if (z == 0) {
		int g = __gcd(xi,m);
		xi /= g,m /= g;
		if (m == 1) {
			if (xi == 1) {
				printf("sqrt(%d)\n",sq);
			}else{
				printf("%d*sqrt(%d)\n",xi,sq);
			}
		}else{
			if (xi == 1) {
				printf("sqrt(%d)/%d\n",sq,m);
			}else{
				printf("%d*sqrt(%d)/%d\n",xi,sq,m);
			}
		}
	}else{// -b != 0
		bool f = false;
		if (z < 0) f = true,z *= -1;
        int m1 = m,m2 = m;
		int g1 = __gcd(xi,m);
		int g2 = __gcd(z,m);
		xi /= g1,z /= g2,m1 /= g1,m2 /= g2;
        if (f) z *= -1;
        if (m2 == 1) {
            printf("%d",z);
        }else{
            printf("%d/%d",z,m2);
        }
		if (m1 == 1) {
			if (xi == 1) {
				printf("+sqrt(%d)\n",sq);
			}else{
				printf("+%d*sqrt(%d)\n",xi,sq);
			}
		}else{
			if (xi == 1) {
				printf("+sqrt(%d)/%d\n",sq,m1);
			}else{
				printf("+%d*sqrt(%d)/%d\n",xi,sq,m1);
			}
		}
	}
}
void solve() {
	int d = b*b-4*a*c;
	if (d == 0) {
		a *= 2;
		b *= -1;
		if (a < 0) {
			b *= -1;
			a *= -1;
		}
		print_frac(b,a);
	}else{
		int sq_d = sq(d);
		if (sq_d * sq_d == d) {
            //cout << sq_d << endl;
			b *= -1;
			a *= 2;
			if (a < 0) {
				b *= -1;
				a *= -1;
			};
            b += sq_d;
			print_frac(b,a);
		}else{
			int m_s = ms(d);
			d /= m_s*m_s;
			b *= -1;
			a *= 2;
			if (a < 0) {
				a *= -1;
				b *= -1;
			}
			print_sqrt(m_s,d,b,a);//a+,b -/+, m_s +;
		}
	}
}
signed main () {
    //freopen("uqe2.in","r",stdin);
    //freopen("ans.out","w",stdout);
	cin >> T >> M;
	init();
	while(T--) {
		cin >> a >> b >> c;
		if (!check(a,b,c)) {
			cout << "NO" << '\n';
			continue;
		}
		solve();
	}
	return 0;
}
