#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int T;
int main() {
    while (++T) {
        cout << T << '\n';
        system("genT3.exe");
        system("T3.exe");
        system("T3bl.exe");
        if (system("fc /n a.out b.out")) {
            system("pause");
        }
    }
    return 0;
}