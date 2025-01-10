#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int T;
const int MN=1e5+15;
struct qj{
    int l,r,v0=0,v1=0;
};
vector<qj> e1,e2;
bool ans1[MN]{},ans2[MN+5]{},vis1[MN],vis2[MN];
int main(){
    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);
    cin>>T;
    while(T--){
        e1.clear();
        e2.clear();
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(ans1,0,sizeof(ans1));
        memset(ans2,0,sizeof(ans2));
        int n;
        string s1,s2,s3,s4;
        cin>>n>>s1>>s2>>s3>>s4;
        bool flag=0;
        qj awa;
        for(int i=0;i<s3.size();i++){
            if((i==s3.size()-1&&s3[i-1]=='0')||(i==0&&s3.size()>1&&s3[i]=='1'&&s3[i+1]=='0')) continue;
            else if(i<s3.size()-1&&s3[i]=='1'&&s3[i-1]=='0'&&s3[i+1]=='0'){
                //cout<<"HAM"<<endl;
                continue;
            }

            else if(flag==0&&s3[i]=='1'){
                    //cout<<"I=l="<<i<<endl;
                awa.l=i;
            flag=1;
                if(s1[i]=='0'){
                    awa.v0++;
                }else awa.v1++;
            }
            else if(flag==1&&s3[i]=='1'){
                if(s1[i]=='0'){
                    awa.v0++;
                }else awa.v1++;
            }
            else if(flag==1&&s3[i]=='0'){
                //cout<<"i=r="<<i<<endl;
                awa.r=i-1;
                flag=0;
                e1.push_back(awa);
                awa.v0=0;
                awa.v1=0;
            }
        }
        //cout<<"E1 "<<e1.size()<<endl;
        flag=0;
        awa.v0=awa.v1=0;
        for(int i=0;i<s4.size();i++){
            if((i==s4.size()-1&&s4[i-1]=='0')||(i==0&&s4.size()>1&&s4[i]=='1'&&s4[i+1]=='0')) continue;
            else if(i<s4.size()-1&&s4[i]=='1'&&s4[i-1]=='0'&&s4[i+1]=='0'){
                continue;
            }

            else if(flag==0&&s4[i]=='1'){
                    //cout<<"i=l="<<i<<endl;
                awa.l=i;
                flag=1;
                if(s2[i]=='0'){
                    awa.v0++;
                }else awa.v1++;
            }
            else if(flag==1&&s4[i]=='1'){
                if(s2[i]=='0'){
                    awa.v0++;
                }else awa.v1++;
            }
            else if(flag==1&&s4[i]=='0'){
                awa.r=i-1;
                //cout<<"i=r="<<i-1<<endl;
                //cout<<"v0="<<awa.v0<<" v1="<<awa.v1<<endl;
                e2.push_back(awa);
                awa.v0=0;
                awa.v1=0;
                flag=0;
            }
        }
        for(int i=0;i<e1.size();i++){
                //cout<<"i:"<<i<<" l:"<<e1[i].l<<" r:"<<e1[i].r<<" v0"<<e1[i].v0<<" v1"<<e1[i].v1<<endl;
            for(int j=e1[i].l;j<=e1[i].r;j++){
                vis1[j]=1;
                if(s2[j]=='1'&&e1[i].v1>0){
                    //cout<<"j:"<<j<<"to 1"<<endl;
                    ans1[j]=1;
                    e1[i].v1--;
                }
                else if(s2[j]=='1'&&e1[i].v1==0){
                    //cout<<"j:"<<j<<"to 0"<<endl;
                    ans1[j]=0;
                    e1[i].v0--;
                    continue;
                }
                if(s2[j]=='0'&&e1[i].v0>0){
                    //cout<<"j:"<<j<<"to 0"<<endl;
                    ans1[j]=0;
                    e1[i].v0--;
                }else if(s2[j]=='0'&&e1[i].v0==0){
                    //cout<<"j:"<<j<<"to 1"<<endl;
                    ans1[j]=1;
                    e1[i].v1--;
                }
            }
        }
        for(int i=0;i<s1.size();i++){
            if(vis1[i]!=1){
                if(s1[i]=='0') ans1[i]=0;
                if(s1[i]=='1') ans1[i]=1;
            }
        }

        for(int i=0;i<e2.size();i++){
            for(int j=e2[i].l;j<=e2[i].r;j++){
                vis2[j]=1;
                if(ans1[j]==1&&e2[i].v1>0){
                    ans2[j]=1;
                    e2[i].v1--;
                }
                else if(ans1[j]==1&&e2[i].v1==0){
                    ans2[j]=0;
                    e2[i].v0--;
                    continue;
                }
                if(ans1[j]==0&&e2[i].v0>0){
                    ans2[j]=0;
                    e2[i].v0--;
                }else if(ans1[j]==0&&e2[i].v0==0){
                    ans2[j]=1;
                    e2[i].v1--;
                }
            }
        }
        for(int i=0;i<s2.size();i++){
            if(vis2[i]!=1){
                if(s2[i]=='0') ans2[i]=0;
                if(s2[i]=='1') ans2[i]=1;
            }
        }
        //for(int i=0;i<s1.size();i++){
        //    cout<<ans1[i]<<" ";
        //}
        //cout<<endl;
        //for(int i=0;i<s2.size();i++){
        //    cout<<ans2[i]<<" ";
        //}
        //cout<<endl;
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(ans1[i]==ans2[i]){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
