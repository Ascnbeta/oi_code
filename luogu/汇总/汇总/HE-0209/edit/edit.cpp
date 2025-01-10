#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1e5+10;

int t,n;
string s1,s2,a,b;
int main(){

    freopen("edit.in","r",stdin);
    freopen("edit.out","w",stdout);

    cin>>t;

    while(t){
        int ans = 0;
        //qingling
        cin>>n;
        cin>>s1>>s2>>a>>b;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i] && a[i] - '0'){
                char t = s1[i];
                for(int j = i+1;j<n;j++){
                    if(s1[j] != s1[i] && a[j]-'0'){

                        //printf("i:%d  s1[i]:%c  j:%d  s1[j]:%c\n",i,s1[i],j,s1[j]);
                        swap(s1[i],s1[j]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i] && b[i] - '0'){
                char t = s2[i];
                for(int j = i+1;j < n; j++){

                        if(s2[j] != s2[i] && b[j]-'0'){
                            //printf("i:%d  s2[i]:%c  j:%d  s2[j]:%c\n",i,s2[i],j,s2[j]);
                            swap(s2[i],s2[j]);
                        }


                }
            }
        }
        for(int i = 0;i<n;i++){
            if(s1[i] == s2[i]) ans++;
        }
        cout<<ans<<endl;
        t--;
    }



    return 0;
}
