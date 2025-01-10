#include<bits/stdc++.h>
using namespace std;
const int MX=201000,INF=0x3f3f3f3f;
inline bool cmp(int a,int b){
    return a>b;
}
int n;
int s1[MX],s2[MX];
int t1[MX],t2[MX];
int qian[MX];string s;
int num[MX][2],cnt,cnt2,num2[MX][2];
int belong[MX],belong2[MX],qian2[MX];
void solve(){
    scanf("%d",&n);cnt=1;cnt2=1;
    cin>>s;
    for(int i=1;i<=n;i++)  s1[i]=s[i-1]-'0',belong[i]=belong2[i]=0;
    cin>>s;
    for(int i=1;i<=n;i++)  s2[i]=s[i-1]-'0';
    cin>>s;
    for(int i=1;i<=n;i++)  t1[i]=s[i-1]-'0';
    cin>>s;
    for(int i=1;i<=n;i++)  t2[i]=s[i-1]-'0';
    t1[n+1]=t2[n+1]=0;
    //input
    for(int i=1;i<=n;i++)  qian[i]=qian[i-1]+s1[i];
    for(int i=1;i<=n;i++)  qian2[i]=qian2[i-1]+s2[i];
    int las=0;
    num[0][0]=num[0][1]=num2[0][0]=num2[0][1]=0;
    for(int i=1;i<=n+1;i++){
        if(!t1[i])  num[cnt][1]=qian[i-1]-qian[las],num[cnt][0]=(i-1-(las+1)+1)-num[cnt][1],cnt++,las=i;
        else  belong[i]=cnt;
    }cnt--;
    //for(int i=1;i<=n;i++)  printf("%d ",belong[i]);printf("  ---belong\n");
    //for(int i=1;i<=cnt;i++)  printf("%d ",num[i][0]);printf("  ---0\n");
    //for(int i=1;i<=cnt;i++)  printf("%d ",num[i][1]);printf("  ---1\n");

    las=0;
    for(int i=1;i<=n+1;i++){
        if(!t2[i])  num2[cnt2][1]=qian2[i-1]-qian2[las],num2[cnt2][0]=(i-1-(las+1)+1)-num2[cnt2][1],cnt2++,las=i;
        else  belong2[i]=cnt2;
    }
    cnt2--;
    //for(int i=1;i<=n;i++)  printf("%d ",belong2[i]);printf("  ---belong\n");
    //for(int i=1;i<=cnt2;i++)  printf("%d ",num2[i][0]);printf("  ---0\n");
    //for(int i=1;i<=cnt2;i++)  printf("%d ",num2[i][1]);printf("  ---1\n");
    int ans=0;
    for(int i=1;i<=n;i++){
        if(t1[i]==0){
            if(t2[i]==0){
                ans+=s1[i]==s2[i];
                continue;
            }
            if(num2[belong2[i]][s1[i]]>0){
                ans++;num2[belong2[i]][s1[i]]--;
            }
            else{
                num2[belong2[i]][!s1[i]]--;
            }
        }
        else if(t2[i]==0){
            if(t1[i]==0){
                ans+=s1[i]==s2[i];
                continue;
            }
            if(num[belong[i]][s2[i]]>0){
                ans++;num[belong[i]][s2[i]]--;
            }
            else{
                num[belong[i]][!s2[i]]--;
            }
        }
        else{
            if(num[belong[i]][0]>0&&num2[belong2[i]][0]>0){
                ans++;
                num[belong[i]][0]--,num2[belong2[i]][0]--;
            }
            else if(num[belong[i]][1]>0&&num2[belong2[i]][1]>0){
                ans++;
                num[belong[i]][1]--,num2[belong2[i]][1]--;
            }
            else{
                if(num[belong[i]][0]>0)  num[belong[i]][0]--;
                else  num[belong[i]][1]--;
                if(num2[belong2[i]][0]>0)  num2[belong2[i]][0]--;
                else  num2[belong2[i]][1]--;
            }
        }
    }
    printf("%d\n",ans);
}
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}
/*
101111111
100111000
110111011
011111111
*/
