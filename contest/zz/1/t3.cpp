#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template <typename T>
inline void read(T &x) {
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
template <typename T>
inline void write(T x) {
    if (x<0) x=-x,putchar('-');
    if (x/10) write(x/10);
    putchar(x%10+'a');
}
const int maxn = 1e5+10;
const ll mod = 998244853;
const ull base = 31;
int T,n,m;ll ans;
ull b[maxn*20];ll b1[maxn*20];
string s[maxn],t[maxn];
vector<int> ds[maxn],dt[maxn];
vector<pair<ull,ll>> ht[maxn],hsr[maxn];
void manacher(string x,vector<int> &d) {
    d.push_back(0);
    int id = 1,r = 0;
    for (int i = 1; i < x.size(); i++) {
        if (i < r) d.push_back(min(r-i,d[id*2-i]));
        else d.push_back(1);
        while (x[i+d[i]]==x[i-d[i]]) ++d[i];
        if (i+d[i]>r) {
            r=i+d[i];
            id=i;
        }
    }
}
void shash(string x,vector<pair<ull,ll>> &ret) {
    ret.push_back({0,0});
    for (int i = 1; i < x.size(); i++) ret.push_back({(ret[i-1].first*base+x[i]-'a'+1),(ret[i-1].second*base%mod+x[i]-'a'+1)%mod});
}
int trie[maxn*20][28];ll val[maxn*20],tot;
map<pair<ull,ll>,ll> mp;
inline void insert(string x) {
    int p = 0;
    for (int i = 1; i <x.size(); i++) {
        if (!trie[p][x[i]-'a']) trie[p][x[i]-'a'] = ++tot;
        p = trie[p][x[i]-'a'];
        ++val[p];
    }
    ++val[p];
}
void calc(int p,pair<ull,ll> v) {
    if (p != 0) {
        mp[v] = val[p];
    }
    for (int i = 0; i < 26; i++) {
        if (trie[p][i]) {
            val[trie[p][i]] += val[p];
            calc(trie[p][i],{(v.first*base+i+1),(v.second*base%mod+i+1)%mod});
            trie[p][i] = 0;
        }
    }
    val[p] = 0;
}
inline bool checks(int pt,int pos,int len) {
    int r = pos-ds[pt][pos],l = pos-len+1;
    if (r<l) return true;
    int sz = s[pt].size()-1;
    int l1 = sz-r+1,r1 = sz-l+1;
    l = l1,r = r1;
    if (l <= 0 || r >= s[pt].size()) return false;
    pair<ull,ll> tmp = {hsr[pt][r].first-hsr[pt][l-1].first*b[r-l+1],((hsr[pt][r].second-hsr[pt][l-1].second*b1[r-l+1]%mod)%mod+mod)%mod};
    if (mp.count(tmp) != 0) return true;
    return false;
}
inline bool checkt(int pt,int pos,int len) {
    int l = pos+dt[pt][pos],r = pos+len-1;
    if (r<l) return true;
    // int sz = s[pt].size();
    // int l1 = sz-r+1,r1 = sz-l+1;
    // l = l1,r = r1;
    if (l <= 0 || r >= t[pt].size()) return false;
    pair<ull,ll> tmp = {ht[pt][r].first-ht[pt][l-1].first*b[r-l+1],((ht[pt][r].second-ht[pt][l-1].second*b1[r-l+1]%mod)%mod+mod)%mod};
    if (mp.count(tmp) != 0) return true;
    return false;
}
signed main () {
#ifdef LOCAL
    freopen("D:/codes/exe/a.in","r",stdin);
    freopen("D:/codes/exe/a.out","w",stdout);
#endif
#ifndef LOCAL
    freopen("str.in","r",stdin);
    freopen("str.out","w",stdout);
#endif
    cin >> T;
    b[0] = b1[0] = 1;
    for (int i = 1; i <= 2000000; i++) b[i]=b[i-1]*base,b1[i]=b1[i-1]*base%mod;
    while (T--) {
        cin >> n >> m;
        ans = 0;
        for (int i = 1; i <= n; i++) cin >> s[i],s[i]=' '+s[i];
        for (int i = 1; i <= m; i++) cin >> t[i],t[i]=' '+t[i];
        
        for (int i = 1; i <= n; i++) {
            manacher(s[i],ds[i]);
            reverse(s[i].begin()+1,s[i].end());
            shash(s[i],hsr[i]);
            reverse(s[i].begin()+1,s[i].end());
        }
        for (int i = 1; i <= m; i++) manacher(t[i],dt[i]),shash(t[i],ht[i]);
        // puts("qwq");
        // for (int i = 1; i <= m; i++) {
            // for (int j : ht[i]) cout << j << ' ';
            // cout << '\n';
        // }
        // puts("qwq");
        tot = 0;
        for (int i = 1; i <= m; i++) insert(t[i]);
        mp.clear();
        calc(0,{0,0});
        memset(val,0,sizeof(val));
        memset(trie,0,sizeof(trie));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < s[i].size(); j++) {
                // cout << ans << '\n';
                ans += m*ds[i][j];
                // cout << ans << '\n';
                if (j+ds[i][j]!=s[i].size()) continue;
                int l = ds[i][j],r = j,tmp = l;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (checks(i,j,mid)) {
                        tmp = mid;
                        l = mid+1;
                    }else{
                        r = mid-1;
                    }
                }
                
                r = j-ds[i][j],l = j-tmp+1;
                if (r<l) continue;
                // cout << 's' << ' ' << i << ' ' << j << ' ' << tmp << '\n';
                int sz = s[i].size()-1;
                int l1 = sz-r+1,r1 = sz-l+1;
                l = l1,r = r1;
                pair<ull,ll> t1 = {hsr[i][r].first-hsr[i][l-1].first*b[r-l+1],((hsr[i][r].second-hsr[i][l-1].second*b1[r-l+1]%mod)%mod+mod)%mod};
                ans += mp[t1];
            }
        }
        mp.clear();
        tot = 0;
        for (int i = 1; i <= n; i++) reverse(s[i].begin()+1,s[i].end()),insert(s[i]);
        // for (int i = 1; i <= tot; i++) cout << val[i] << '\n';
        // puts("tmbcan");
        calc(0,{0,0});
        memset(val,0,sizeof(val));
        memset(trie,0,sizeof(trie));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j < t[i].size(); j++) {
                // cout << ans << '\n';
                ans += n*dt[i][j];
                // cout << ans << '\n';
                if (j-dt[i][j]!=0) continue;
                int l = dt[i][j],r = t[i].size()-j,tmp = l;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (checkt(i,j,mid)) {
                        tmp = mid;
                        l = mid+1;
                    }else{
                        r = mid-1;
                    }
                }
                
                l = j+dt[i][j],r = j+tmp-1;
                if (r<l) continue;
                // cout << 't' << ' ' << i << ' ' << j << ' ' << tmp << '\n';
                pair<ull,ll> t1 = {ht[i][r].first-ht[i][l-1].first*b[r-l+1],((ht[i][r].second-ht[i][l-1].second*b1[r-l+1]%mod)%mod+mod)%mod};
                // cout << l << ' ' << r << '\n';
                // printf("kaito%lld\n",t1);
                ans += mp[t1];
            }
        }
        for (int i = 1; i <= n; i++) {
            ds[i].clear(),ds[i].shrink_to_fit();
            hsr[i].clear(),hsr[i].shrink_to_fit();
        }
        for (int i = 1; i <= m; i++) {
            dt[i].clear(),dt[i].shrink_to_fit();
            ht[i].clear(),ht[i].shrink_to_fit();
        }
        printf("%lld\n",ans);
    }
    return 0;
}