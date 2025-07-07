#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
const ll mod = 998244353;
int n,a[maxn],b[13];ll ans;
vector<int> v2,v3;
ll jc[maxn],jc_inv[maxn];
inline ll binpow(ll base,ll b) {
    ll ret = 1;
    while (b) {
        if (b&1ll) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1ll; 
    }
    return ret;
}
int pos6[maxn];
inline ll C(int n,int m) {
    return jc[n] * jc_inv[n-m] % mod * jc_inv[m] % mod;
}
int main() {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
    cin >> n;
    jc[0] = jc_inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        jc[i] = jc[i-1]*i%mod;
        jc_inv[i] = binpow(jc[i],mod-2);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]%2==0) v2.push_back(a[i]);
        if (a[i]%3==0) v3.push_back(a[i]);
        if (flag&&a[i]!=1&&a[i]!=2&&a[i]!=3) flag = false;
    }
    // if (n <= 10) {
    //     int r[13],tmp[13];
    //     memset(tmp,0,sizeof(tmp));
    //     for (int i = 1; i <= n; i++) tmp[a[i]]++;
    //     for (int i = 1; i <= n; i++) r[i] = i;
    //     do{
            
    //         vector<int> c2,c3;
    //         for (int i = 1; i <= n; i++) {
    //             b[i] = a[r[i]];
                
    //             if (b[i]%2==0) c2.push_back(b[i]);
    //             if (b[i]%3==0) c3.push_back(b[i]);
    //         }
    //         if (c2 == v2 && c3 == v3) ++ans;
    //     }while (next_permutation(r+1,r+n+1));
    //     for (int i = 1; i <= 9; i++) ans = ans * jc_inv[tmp[i]] % mod;
    //     cout << ans << '\n';
    // }else 
    if (flag) {
        for (int i = 1; i <= n; i++) {
            b[a[i]]++;
        }
        cout << jc[n]*jc_inv[b[1]]%mod*jc_inv[b[2]]%mod*jc_inv[b[3]]%mod << '\n';
    }
    else{
        ans = 1;
        v2.clear(),v3.clear();
        for (int i = 1; i <= n; i++) {
            b[a[i]]++;
            if (a[i]%2==0) {
                v2.push_back(i);
                if (a[i]==6){
                    pos6[i]=v2.size();
                }
            }
            if(a[i]%3==0) {
                v3.push_back(i);
            }
        }
        int lst = 0,lst6v3 = 0;
        for (int i = 0; i < v3.size(); i++) {
            if (a[v3[i]] == 6) {
                int pos = pos6[v3[i]];
                int tmp = pos - lst;//偶数中两个6中间有几个空
                lst = pos;
                int pre = i-lst6v3;//两个6中间有几个3,9
                lst6v3 = i+1;
                ans = ans * C(tmp-1+pre,pre) % mod;//式子不对
            }
        }
         ans = ans * C(v2.size()-lst+v3.size()-lst6v3,v3.size()-lst6v3) % mod;
        // ans = ans * binpow(v2.size()-lst+1,v3.size()-lst6v3) % mod;//式子不对
        int tot = 0;
        for (int i = 1; i <= 10; i++) if (i==1||i==5||i==7) tot += b[i];
        //统计1,5,7总个数
        int lft = n - tot;//剩下多少数字
        ++lft;
        for (int i = 1; i <= tot; i++) ans = ans * lft % mod,++lft;
        ans = ans * jc_inv[b[1]] % mod * jc_inv[b[5]] % mod * jc_inv[b[7]] % mod;
        cout << ans << '\n';
    }
    return 0;
}