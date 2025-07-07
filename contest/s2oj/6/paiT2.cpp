#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int T;
int main() {
    while (++T) {
        cout << T << '\n';
        system("genT2.exe");
        system("T2.exe");
        system("T2bl.exe");
        if (system("fc /n a.out b.out")) {
            system("pause");
        }
    }
    return 0;
}