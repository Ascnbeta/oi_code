#include<bits/stdc++.h>
using namespace std;
namespace code{
    #define F(i,x,y) for(int i=(x);i<=(y);i++)
    #define debug(x) cerr<<#x<<'='<<x<<endl
    string s1,s2,t1,t2;
    constexpr int N=100005;
    int main(){
        freopen("edit.in","r",stdin);
        freopen("edit.out","w",stdout);
        cin.tie(0)->sync_with_stdio(0);
        int T;
        cin>>T;
        while(T--){
            int n;
            cin>>n>>s1>>s2>>t1>>t2;
            s1='0'+s1;
            s2='0'+s2;
            t1='0'+t1;
            t2='0'+t2;
            bool A=1;
            F(i,2,n){
                if(s1[i]!=s1[i-1]){
                    A=0;
                    break;
                }
            }
            if(A){
                int ans=0;
                F(i,1,n){
                    if(s2[i]==s1[1])ans++;
                }
                cout<<ans<<'\n';
                continue;
            }
            else if(t1==t2){
                int ss1=0,ss2=0,tot=0,ans=0;
                F(i,1,n){
                    if(t1[i]=='0'){
                        ans+=min(ss1,ss2)+min(tot-ss1,tot-ss2)+(s1[i]==s2[i]);
                        ss1=ss2=tot=0;
                    }
                    else {
                        tot++;
                        if(s1[i]=='1')ss1++;
                        if(s2[i]=='1')ss2++;
                    }
                }
                ans+=min(ss1,ss2)+min(tot-ss1,tot-ss2);
                cout<<ans<<'\n';
                continue;
            }
        }
        return 0;
    }
}
int main(){code::main();return 0;}
