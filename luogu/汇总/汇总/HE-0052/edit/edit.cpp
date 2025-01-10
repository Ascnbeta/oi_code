#include<bits/stdc++.h>
#define fo(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define fu(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)
using namespace std;
typedef long long ll;
#define lx ll
inline lx qr()
{
    char ch = getchar(); lx x = 0, f = 1;
    for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x * f;
}
#undef lx
#define qr qr()
const int Ratio = 0;
const int N = 1e5 + 5;
int n;
string s1, s2;
int t1[N], t2[N];
namespace Wisadel
{
    short main()
    {
        // freopen(".in", "r", stdin), freopen(".out", "w", stdout);
        freopen("edit.in", "r", stdin), freopen("edit.out", "w", stdout);
        int T = qr;
        while(T--)
        {
            n = qr;
            cin >> s1; s1 = " " + s1;
            cin >> s2; s2 = " " + s2;
            fo(i, 1, n) scanf("%1d", &t1[i]);
            fo(i, 1, n) scanf("%1d", &t2[i]);
            int ha11 = 0, ha10 = 0, ha21 = 0, ha20 = 0;
            int nd11 = 0, nd10 = 0, nd21 = 0, nd20 = 0;
            int ans = 0;
            fo(i, 1, n)
            {
                if(t1[i] == 1) ha11 += (s1[i] == '1'), ha10 += (s1[i] == '0');
                if(t2[i] == 1) ha21 += (s2[i] == '1'), ha20 += (s2[i] == '0');
                if(t1[i] == 0)
                {
                    if(i > 1 && t2[i - 1] == 0) nd10 = (s1[i] == '0'), nd11 = (s1[i] == '1');
                    else nd10 = ha10 + (s1[i] == '0'), nd11 = ha11 + (s1[i] == '1');
                    ha10 = ha11 = 0;
                }
                if(t2[i] == 0)
                {
                    if(i > 1 && t1[i - 1] == 0) nd20 = (s2[i] == '0'), nd21 = (s2[i] == '1');
                    else nd20 = ha20 + (s2[i] == '0'), nd21 = ha21 + (s2[i] == '1');
                    ha20 = ha21 = 0;
                }
                if(t1[i] == 0 && t2[i] == 0)
                {
                    if(s1[i] == s2[i]) ans++;
                    ha10 = ha11 = ha20 = ha21 = 0;
                    nd11 = nd10 = nd21 = nd20 = 0;
                }
                int zc1 = min(ha11, nd21), zc0 = min(ha10, nd20);
                ha11 -= zc1, nd21 -= zc1, ha10 -= zc0, nd20 -= zc0;
                ans += zc1 + zc0;
                zc1 = min(ha21, nd11), zc0 = min(ha20, nd10);
                ha21 -= zc1, nd11 -= zc1, ha20 -= zc0, nd10 -= zc0;
                ans += zc1 + zc0;
                zc1 = min(ha11, ha21), zc0 = min(ha10, ha20);
                ha11 -= zc1, ha21 -= zc1, ha10 -= zc0, ha20 -= zc0;
                ans += zc1 + zc0;
            }
            int zc1 = min(ha11, ha21), zc0 = min(ha10, ha20);
            ha11 -= zc1, ha21 -= zc1, ha10 -= zc0, ha20 -= zc0;
            ans += zc1 + zc0;
            printf("%d\n", ans);
        }
        return Ratio;
    }
}
signed main(){return Wisadel::main();}