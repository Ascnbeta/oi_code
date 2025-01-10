#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int a[N],b[N],fl1[N],fl2[N];
int s1[2],s2[2],s[2];
int ans;
int ch(int mx,int op){
    int no=min(s1[0],s2[0])+min(s1[1],s2[1]);
    if(op==0){
        if(s1[0]>min(s1[0],s2[0])){
            int de=min(s[0],s1[0]-min(s1[0],s2[0]));
            s1[0]-=de;
            s1[1]+=de;
        }
        if(s2[0]>min(s1[0],s2[0])){
            int de=min(s[1],s2[0]-min(s1[0],s2[0]));
            s2[0]-=de;
            s2[1]+=de;
        }
        no=min(s1[0],s2[0])+min(s1[1],s2[1]);
        no=min(no,mx);
        s1[0]=s1[1]=s2[0]=s2[1]=s[0]=s[1]=0;
        return no;
    }
    if(op==1){
        if(s1[0]>min(s1[0],s2[0])){
            int de=min(s[0],s1[0]-min(s1[0],s2[0]));
            s[0]-=de;
            s1[0]-=de;
            s1[1]+=de;
        }
        if(s2[0]>min(s1[0],s2[0])){
            int de=min(s[1],s2[0]-min(s1[0],s2[0]));
            s[1]-=de;
            s2[0]-=de;
            s2[1]+=de;
        }
        no=min(s1[0],s2[0])+min(s1[1],s2[1]);
        if(no>mx){
            int tt=max(0,mx-min(s1[1],s2[1]));
            s[1]+=min(mx,min(min(s1[1],s2[1]),min(s1[0],s2[0])-tt));
            s2[1]-=min(mx,min(s1[1],s2[1]));
            s2[0]-=tt;
            no=mx;
        }
        else{
            s2[0]-=min(s1[0],s2[0]);
            s2[1]-=min(s1[1],s2[1]);
        }
        s1[0]=s1[1]=s[0]=0;
        return no;
    }
    if(s1[0]>min(s1[0],s2[0])){
        int de=min(s[0],s1[0]-min(s1[0],s2[0]));
        s[0]-=de;
        s1[0]-=de;
        s1[1]+=de;
    }
    if(s2[0]>min(s1[0],s2[0])){
        int de=min(s[1],s2[0]-min(s1[0],s2[0]));
        s[1]-=de;
        s2[0]-=de;
        s2[1]+=de;
    }
    no=min(s1[0],s2[0])+min(s1[1],s2[1]);
    if(no>mx){
        int tt=max(0,mx-min(s1[1],s2[1]));
        s[0]+=min(mx,min(min(s1[1],s2[1]),min(s1[0],s2[0])-tt));
        s1[1]-=min(mx,min(s1[1],s2[1]));
        s1[0]-=tt;
        no=mx;
    }
    else{
        s1[0]-=min(s1[0],s2[0]);
        s1[1]-=min(s1[1],s2[1]);
    }
    s2[0]=s2[1]=s[1]=0;
    return no;
}
int main(){
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        s1[0]=s1[1]=0;
        s2[0]=s2[1]=0;
        s[0]=s[1]=0;
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;++i){
            scanf("%1d",&a[i]);
        }
        for(int i=1;i<=n;++i){
            scanf("%1d",&b[i]);
        }
        for(int i=1;i<=n;++i){
            scanf("%1d",&fl1[i]);
            fl1[i]^=1;
        }
        for(int i=1;i<=n;++i){
            scanf("%1d",&fl2[i]);
            fl2[i]^=1;
        }
        int r1=0,r2=0;
        int la=0;
        for(int i=1;i<=n;++i){
            r1=max(r1,i-1);
            r2=max(r2,i-1);
            while(r1!=n&&!fl1[r1+1]){
                ++r1;
                s1[a[r1]]++;
            }
            while(r2!=n&&!fl2[r2+1]){
                ++r2;
                s2[b[r2]]++;
            }
            if(fl1[i]&&fl2[i]){
                ans+=ch(i-la-1,0);
                ans+=(a[i]==b[i]);
                la=i;
                continue;
            }
            if(fl1[i]){
                if(s2[a[i]]){
                    ++ans;
                    s2[a[i]]--;
                }
                else if(a[i]&&s[1]&&s2[0]){
                    s2[0]--;
                    s[1]--;
                    ++ans;
                }
                ans+=ch(i-la-1,1);
                la=i;
                continue;
            }
            if(fl2[i]){
                if(s1[b[i]]){
                    ++ans;
                    s1[b[i]]--;
                }
                else if(b[i]&&s[0]&&s1[0]){
                    s1[0]--;
                    s[0]--;
                    ++ans;
                }
                ans+=ch(i-la-1,2);
                la=i;
                continue;
            }
        }
        ans+=ch(n-la,0);
        printf("%d\n",ans);
    }
    return 0;
}
