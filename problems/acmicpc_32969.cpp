#include <iostream>
#include <string>
using namespace std;
string const digital_humanities[] { "social", "history", "language", "literacy" };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    for(string const &t : digital_humanities) {
        for(int i = 0; i + t.size() <= s.size(); i++) {
            if(s.substr(i, t.size()) == t) {
                cout << "digital humanities";
                return 0;
            }
        }
    }
    cout << "public bigdata";
}
