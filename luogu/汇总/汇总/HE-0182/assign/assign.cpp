#include <iostream>
#include <map>

typedef unsigned long long ULL;

const ULL mod = 1E+9 + 7;
const ULL maxn = 1E+9;

int T, m;
ULL n, v, o = 0;
std::map<ULL, ULL> p;

int main()
{
	using namespace std;
	
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	
	cin >> T;
	
	while (T--)
	{
		o = 0;
		p.clear();
		
		cin >> n >> m >> v;
		bool f = false;
		for (int i = 0; i < m; i++)
		{
			ULL aa, bb;
			cin >> aa >> bb;
			aa--;
			if (p.find(aa) != p.end()) if (p[aa] != bb) f = true;
			p[aa] = bb;
		}
		if (f)
		{
			cout << o << endl;
			continue;
		}
		
		o = 1;
		for (int i = 0; i < p.begin() -> first; i++)
		{
			ULL d = v * v % mod;
			o = (o * d) % mod;
		}
		for (int i = p.begin() -> first; i < p.rend() -> first + 1; i++)
		{
			ULL d;
			if (p.find(i) != p.end() && p.find(i + 1) != p.end())
			{
				d = (v * (v - 1)) % mod + 1;
			}
			else if (p.find(i) != p.end())
			{
				d = v * v % mod;
			}
			else if (p.find(i + 1) != p.end())
			{
				d = v * v % mod;
			}
			else
			{
				d = v * v % mod;
			}
			o = (o * d) % mod;
		}
		for (int i = p.rend() -> first + 1; i < n - 1; i++)
		{
			ULL d = v * v % mod;
			o = (o * d) % mod;
		}
		
		cout << o << endl;
	}
		
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
