#include <bits/stdc++.h>
using namespace std;

int num[200003],mx[200003],len=0;

int main() {
    ios::sync_with_stdio(0);
    int m,d; cin>>m>>d;
    int t=0; 
    for (int i=1;i<=m;i++) {
        char ch; cin>>ch;
        int x; cin>>x;
        if (ch=='Q') {
            cout<<mx[len+1-x]<<endl;
            t=mx[len+1-x]%d;
        }
        else {
            num[++len]=((long long)t+x)%d;
            mx[len]=num[len];
            for (int i=len-1;i>=1;i--) 
                if (mx[i]<num[len]) mx[i]=num[len];
                else break;
        }
    }
    return 0;
}