#include <iostream>
#include <sstream>
#include <string>
using namespace std;
inline int get_int() { string s; getline(cin, s); return stoi(s); }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = get_int(); while(t--) {
        string s; getline(cin, s);
        stringstream ss(s);
        string str; while(ss >> str) {
            int m{}, o{};
            for(char c : str) {
                m += (c == 'M');
                o += (c == 'O');
            }
            cout << static_cast<char>((m << 4) + o);
        } cout << '\n';
    }
}