#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

#define N 100005

inline int R() {
    int x=0; bool f=0; char c=getchar();
    while (!isdigit(c)) f|=(c=='-'),c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    return f?-x:x;
}

template<typename T>
void W(T x,char Extra=0) {
    if (x<0) putchar('-'),x=-x; if (x>9) W(x/10);
    putchar(x%10+'0'); if (Extra) putchar(Extra);
}

using namespace std;
int n,bel[N],num[N],ll[N],rr[N],l[N],r[N],Cnt[N]; string s1,s2,t1,t2;

int main() {
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    int T=R();
    while (T--) {
        n=R(); cin>>s1>>s2>>t1>>t2;
        s1=" "+s1,s2=" "+s2,t1=" "+t1,t2=" "+t2;
        memset(ll,0,(n+1)*sizeof(ll[0]));
        memset(rr,0,(n+1)*sizeof(rr[0]));
        memset(num,0,(n+1)*sizeof(num[0]));
        int cnt=1;
        for (int i=1;i<=n;i++) {
            if (t1[i]=='0') ++cnt,ll[cnt]=rr[cnt]=i,bel[i]=cnt,num[cnt]=(s1[i]=='1'),++cnt;
            else bel[i]=cnt,num[cnt]+=(s1[i]=='1'),rr[cnt]=i,ll[cnt]=(ll[cnt]==0?i:ll[cnt]);
        }
        if (ll[cnt]==0 and rr[cnt]==0) --cnt;
        // printf("1:\n");
        // for (int i=1;i<=cnt;i++) W(ll[i],' '),W(rr[i],' '),W(num[i],'\n');
        memset(l,0,(n+1)*sizeof(l[0]));
        memset(r,0,(n+1)*sizeof(r[0]));
        memset(Cnt,0,(n+1)*sizeof(Cnt[0]));
        int tot=1;
        for (int i=1;i<=n;i++) {
            if (t2[i]=='0') ++tot,l[tot]=r[tot]=i,Cnt[tot]=(s2[i]=='1'),++tot;
            else r[tot]=i,l[tot]=(l[tot]==0?i:l[tot]),Cnt[tot]+=(s2[i]=='1');
        }
        if (l[tot]==0 and r[tot]==0) --tot;
        // printf("2:\n");
        // for (int i=1;i<=tot;i++) W(l[i],' '),W(r[i],' '),W(Cnt[i],'\n');
        for (int i=1;i<=tot;i++)
            for (int j=l[i];j<=r[i];j++)
                if (j==l[i] or bel[j]!=bel[j-1]) {
                    int tmp=min({Cnt[i],num[bel[j]],min(r[i],rr[bel[j]])-max(l[i],ll[bel[j]])+1});
                    num[bel[j]]-=tmp,Cnt[i]-=tmp;
                    if (!Cnt[i]) break;
                }
        int ans=0;
        for (int i=1;i<=cnt;i++) ans+=num[i];
        for (int i=1;i<=tot;i++) ans+=Cnt[i];
        W(n-ans,'\n');
    }
    return 0;
}