#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
u32string s1[132] = {
U"Dot to Dot feat. shully",
U"Innocence",
U"INTERNET OVERDOSE",
U"Call My Name feat. Yukacco",
U"dropdead",
U"IONOSTREAM",
U"Surrender",
U"Astral tale",
U"Auxesia",
U"Avant Raze",
U"Be There",
U"Can I Friend You on Bassbook? Lol",
U"carmine:scythe",
U"cocoro*cosmetic",
U"CROSS✝︎SOUL",
U"DataErr0r",
U"Distorted Fate",
U"Empire of Winter",
U"Evening in Scarlet",
U"Fallensquare",
U"Feels So Right feat. Renko",
U"Floating World",
U"Galactic Love",
U"Head BONK ache",
U"Impure Bird",
U"La'qryma of the Wasteland",
U"lastendconductor",
U"Libertas",
U"MAHOROBA",
U"Phantasia",
U"PICO-Pico-Translation!",
U"Teriqma",
U"Yosakura Fubuki",
U"Your voice so... feat. Such",
U"Altale",
U"amygdata",
U"Beautiful Dreamer",
U"B.B.K.K.B.K.K.",
U"BADTEK",
U"BATTLE NO.1",
U"Dreadnought",
U"Désive",
U"Einherjar Joker",
U"Filament",
U"Galaxy Friends",
U"goldenslaughterer",
U"Heavenly caress",
U"init()",
U"INTERNET YAMERO",
U"LIVHT MY WΔY",
U"Lost in the Abyss",
U"Luna Rossa",
U"Macrocosmic Modulation",
U"New York Back Raise",
U"SACRIFICE feat. ayame",
U"Scarlet Cage",
U"Summer Fireworks of Love",
U"The Survivor (Game Edit)",
U"THE ULTIMACY",
U"To the Furthest Dream",
U"Twilight Concerto",
U"Xeraphinite",
U"μ",
U"Alexandrite",
U"AttraqtiA",
U"Aurgelmir",
U"Back to Basics",
U"Capella",
U"Chromafill",
U"Crimson Throne",
U"Free Myself",
U"GIMME DA BLOOD",
U"Hiiro Gekka, Kyoushou no Zetsu (nayuta 2017 ver.)",
U"IZANA",
U"Kanbu de Tomatte Sugu Tokeru",
U"Kissing Lucifer",
U"Malicious Mischance",
U"Manic Jeer",
U"Masquerade Legion",
U"Metallic Punisher",
U"MIRINAE",
U"Mirzam",
U"Modelista",
U"NEO WINGS",
U"NULL APOPHENIA",
U"PUPA",
U"Qovat",
U"Redolent Shape",
U"Sheriruth (Laur Remix)",
U"To the Milky Way",
U"ultradiaxon-N3",
U"Wish Upon a Snow",
U"Xanatos",
U"γuarδina",
U"BUCHiGiRE Berserker",
U"KYOREN ROMANCE",
U"PRIMITIVE LIGHTS",
U"REKKA RESONANCE",
U"SAIKYO STRONGER",
};
u32string song[21],screen[21];
string to_utf8(u32string s) {
    return wstring_convert< codecvt_utf8<char32_t>,char32_t >{}.to_bytes(s);
}
u32string to_utf32(string s) {
    return wstring_convert< codecvt_utf8<char32_t>,char32_t >{}.from_bytes(s);
}
int main () {
    SetConsoleOutputCP(CP_UTF8);
    int seed;
    cout << "请输入随机种" << endl;
    cin >> seed;
    srand(seed);
    cout << "请输入曲目个数" << endl;
    int num;
    cin >> num;
    system("cls");
    for (int i = 1; i <= num; i++) {
        int tmp = rand() % 99;
        song[i] = s1[tmp];
        for (int j = 0; j < song[i].size(); j++) {
            screen[i] += U'*';
        }
    }
    for (int i = 1; i <= num; i++) {
        cout << wstring_convert< codecvt_utf8<char32_t>,char32_t >{}.to_bytes(screen[i]) << endl;
    }
    while (1) {
        Sleep(2000);
        cout << "请输入你要开的字符（禁开空格）" << endl;
        string s;
        u32string s1;
        cin >> s;
        s1 = wstring_convert< codecvt_utf8<char32_t>,char32_t >{}.from_bytes(s);
        for (int i = 1; i <= num; i++) {
            for (int j = 0; j < song[i].size(); j++) {
                if (to_utf8(song[i])[j] == to_utf8(s1)[0] || to_utf8(song[i])[j] -'A' + 'a'== to_utf8(s1)[0]) {
                    screen[i][j] = song[i][j];
                }
            }
        }
        system("cls");
        for (int i = 1; i <= num; i++) {
            cout << to_utf8(screen[i]) << endl;
        }
    }
    
    return 0;
}