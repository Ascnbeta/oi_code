#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int b1[N],b2[N],ans,b10[N],b20[N];
int main(){
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    int t;cin>>t;
    while(t--){
            ans=0;
        int n;cin>>n;
        string s1,s2,t1,t2;
        cin>>s1>>s2>>t1>>t2;
        s1=" "+s1;s2=" "+s2;t1=" "+t1;t2=" "+t2;
        int st1=0,st2=0,cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            b1[i]=-1;
            b2[i]=-1;
            b10[i]=-1;
            b20[i]=-1;
        }
        for(int i=1;i<=n;i++){
            if(t1[i]=='0'){
                st1=i;
                b1[i]=s1[i]-'0';
                b10[i]=1-b1[i];
            }else{
                if(b1[st1+1]==-1) b1[st1+1]=0;
                if(b10[st1+1]==-1) b10[st1+1]=0;
                if(s1[i]=='1') {
                    b1[st1+1]++;
                }
                else b10[st1+1]++;
            }
            if(t2[i]=='0'){
                st2=i;
                b2[i]=s2[i]-'0';
                b20[i]=1-b2[i];
            }else{
                if(b2[st2+1]==-1) b2[st2+1]=0;
                if(b20[st2+1]==-1) b20[st2+1]=0;
                if(s2[i]=='1') b2[st2+1]++;
                else b20[st2+1]++;
            }
        }
        for(int i=1;i<=n;i++){
                if(b1[i]==-1){
                    b1[i]=b1[i-1];
                }
                if(b2[i]==-1){
                    b2[i]=b2[i-1];
                }
                if(b10[i]==-1){
                    b10[i]=b10[i-1];
                }
                if(b20[i]==-1){
                    b20[i]=b20[i-1];
                }
                if(b1[i]>0&&b2[i]>0){
                    ans++;
                    b1[i]--;b2[i]--;

                }else{
                    if(b10[i]>0&&b20[i]>0){
                    ans++;
                    b10[i]--;b20[i]--;

                    }
                }
            }
            cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
