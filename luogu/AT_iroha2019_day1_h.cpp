#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int g(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}//ͳ�Ƹ���λ֮��
string t(int y) {
    string ret = "";
    int x = y / 9;
    if (y % 9 != 0) ret += y % 9 + '0';
    while(x--) ret += '9';
    return ret;
}//���ɸ���λ֮��Ϊnn������X
signed main () {
    cin >> n;
    int nn = g(n);
    string s = t(nn);
    //cout << s << '\n';
    if (stoll(s) == n) {//���X == N
        if (s.size() == 1) {
            s[0] -= 1;
            s = '1' + s;//����1<=N<=9����������ǰ�油1����λ�ϵ�����1
        }else{
            if (s[0] == '9') {
                s[0] -= 1;
                s = '1' + s;//���ڸ���λ��ȫ��9�����������λ��1����������ǰ��1
            }else{
                s[1] -= 1;
                s[0] += 1;//���ڳ����λ��ȫ��9�������θ�λ��1�����λ��1
            }
        }
        cout << s;
    }else{
        cout << s;
    }
    return 0;
}