#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t,p) for(int i = s;i <= t;i += p)
#define drep(i,s,t,p) for(int i = s;i >= t;i -= p)
#ifdef LOCAL
    FILE *I = freopen("in.in","r",stdin),*O = freopen("ans.ans","w",stdout);
    // FILE *E = freopen("err.err","w",stderr);
#else
    FILE *I = freopen("edit.in","r",stdin),*O = freopen("edit.out","w",stdout);
#endif
using ll = long long;using ull = unsigned long long;
using db = double;using ldb = long double;
const int N = 1e5 + 10;
char s1[N],s2[N],t1[N],t2[N];
int n,r1[N],r2[N],l1[N],l2[N];
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> > p1[2],p2[2];
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
int T;cin>>T;
while(T--){
    cin>>n>>(s1+1)>>(s2+1)>>(t1+1)>>(t2+1);
    memset(r1,0,sizeof r1);memset(r2,0,sizeof r2);
    memset(l1,0,sizeof l1);memset(l2,0,sizeof l2);
    int now = n,ans = 0;
    drep(i,n,1,1){
        if(t1[i] == '0') r1[i] = i,now = i - 1;
        else r1[i] = now;
    }
    now = n;
    drep(i,n,1,1){
        if(t2[i] == '0') r2[i] = i,now = i - 1;
        else r2[i] = now;
    }
    now = 1;
    rep(i,1,n,1){
        if(t1[i] == '0') l1[i] = i,now = i + 1;
        else l1[i] = now;
    }
    now = 1;
    rep(i,1,n,1){
        if(t2[i] == '0') l2[i] = i,now = i + 1;
        else l2[i] = now;
    }
    priority_queue<pii,vector<pii>,greater<pii> > ().swap(p1[0]);
    priority_queue<pii,vector<pii>,greater<pii> > ().swap(p1[1]);
    priority_queue<pii,vector<pii>,greater<pii> > ().swap(p2[0]);
    priority_queue<pii,vector<pii>,greater<pii> > ().swap(p2[1]);
    auto del = [](priority_queue<pii,vector<pii>,greater<pii> > &st,int pos){
        while(st.size() && st.top().first < pos) st.pop();
    };
    int epos = 0;
    set<int> vis;
    rep(i,1,n+1,1) vis.insert(i);
    rep(i,1,n,1){
        int x;bool flag;
        x = s1[i] - '0';
        del(p2[x],l1[i]);
        flag = true;
        if(p2[x].size()){
            while(p2[x].size()){
                int p = p2[x].top().second;p2[x].pop();
                int pos = *vis.upper_bound((max(l1[i],l2[p])-1));
                if(pos == n+1) break;
                if(min(r2[p],r1[i]) >= pos){ans++;vis.erase(pos);flag = false;break;}
            }
        }
        if(flag) p1[x].emplace(r1[i],i);

        x = s2[i] - '0';
        del(p1[x],l2[i]);
        flag = true;
        if(p1[x].size()){
            while(p1[x].size()){
                int p = p1[x].top().second;p1[x].pop();
                int pos = *vis.upper_bound((max(l2[i],l1[p])-1));
                if(pos == n+1) break;
                if(min(r1[p],r2[i]) >= pos){ans++;vis.erase(pos);flag = false;break;}
            }
        }
        if(flag) p2[x].emplace(r2[i],i);
    }
    cout<<ans<<'\n';
}
}