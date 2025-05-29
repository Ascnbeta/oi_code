#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e3+20;
const int maxm = 3e4+30;
inline void read(int &x) {
    x=0;int f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
int n;
int t[maxn][5];
int f[maxm];

int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    read(n);
    for (int i = 1; i <= n; i++) {
        read(t[i][1]),read(t[i][2]),read(t[i][3]);
    }
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 5*n; j >= 0; j--) {
            int tmp1=0x3f3f3f3f,tmp2 = f[j]+t[i][2],tmp3=0x3f3f3f3f;
            if (t[i][2] == 0) tmp2 = 0x3f3f3f3f;
            if (j >= t[i][1] && t[i][1] != 0) tmp1 = f[j-t[i][1]];
            if (j >= t[i][3] && t[i][3] != 0) tmp3 = f[j-t[i][3]]+t[i][3];
            f[j] = min(tmp1,min(tmp2,tmp3));
        }   
    }   
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= 5*n; i++) ans = min(ans,max(i,f[i]));
    printf("%d",ans);
    return 0;
}