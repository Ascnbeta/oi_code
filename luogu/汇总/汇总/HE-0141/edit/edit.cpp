#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int s1c1,s1c0,s2c1,s2c0;
char tar1[N],tar2[N]; 
string s1,s2,s3,s4;
int n;
void baoli();
void subtask2();
void subtask3();
void solve(){
    cin>>n;
    s1c1=0,s1c0=0,s2c1=0,s2c0=0;
    for(int i=0;i<n;++i){
        tar1[i]='x';
        tar2[i]='x';
    }
    cin>>s1>>s2>>s3>>s4;
    if(s3==s4){
        subtask3();
        cerr<<"subtask3"<<endl;
        return;
    }
    for(int i=1;i<n;++i){
        if(s1[i]!=s1[i-1])
            goto ot;
    }
    subtask2();
    cerr<<"subtask2"<<endl;
    return;
    ot:
    baoli();
    cerr<<"BL"<<endl;

}

int main(){
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout); 
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
void subtask2(){
    int ans=0;
    for(int i=0;i<n;++i){
        if(s1[i]==s2[i])
            ++ans;
    }
    cout<<ans<<endl;
}
void subtask3(){
    int ans=0;
    for(int i=0;i<n;++i){
        
        if(s3[i]!='0')
        {
            if(s1[i]=='0')
                s1c0++;
            else
                s1c1++;
            if(s2[i]=='0')
                s2c0++;
            else
                s2c1++;
            if(i==n-1)
            {
                ans+=min(s1c1,s2c1);
                ans+=min(s1c0,s2c0);

                s1c1=0,s1c0=0,s2c1=0,s2c0=0;
            }
        }
        else{
            ans+=min(s1c1,s2c1);
            ans+=min(s1c0,s2c0);
            if(s1[i]==s2[i])
                ans++;
            s1c1=0,s1c0=0,s2c1=0,s2c0=0;
        }
    }
    cout<<ans<<endl;
}
void baoli(){
        int ans=0;
    for(int i=0;i<n;++i){
        if(s1[i]==s2[i])
            ++ans;
    }
    cout<<ans<<endl;
}
