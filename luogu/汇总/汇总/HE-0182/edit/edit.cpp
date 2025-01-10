#include <iostream>
#include <cmath>

const int maxn = 1E+5;

int T, n, o = 0;
bool a[maxn], b[maxn], p[maxn], q[maxn];

void input(bool*, int);

int main()
{
	using namespace std;
	
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
	
	cin >> T;
	
	while (T--)
	{
		o = 0;
		
		cin >> n;
		input(a, n);
		input(b, n);
		input(p, n);
		input(q, n);
		
		int cta = 0, cfa = 0, ctb = 0, cfb = 0;
		for (int i = 0; i < n; i++)
		{
			if (!p[i] && !q[i] && a[i]==b[i])
			{
				o++;
				continue;
			}
			if (p[i])
			{
				if (a[i]) cta++;
				else cfa++;
			}
			else
			{
				//o++;
//				if (a[i]) ctb--;
//				else cfb--;
			}
			if (q[i])
			{
				if (b[i]) ctb++;
				else cfb++;
			}
			else
			{
				//o++;
//				if (b[i]) cta--;
//				else cfa--;
			}
		}
		
		o += min(cta, ctb) + min(cfa, cfb);
		
		cout << o << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

void input(bool* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		char c;
		std::cin >> c;
		a[i] = c - '0';
	}
}
