#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s;
    getline(cin, s);
    int n = stoi(s);
    while(n--) {
        getline(cin, s);
        if(s != "Never gonna give you up" && s != "Never gonna let you down" && s != "Never gonna run around and desert you" && s != "Never gonna make you cry" && s != "Never gonna say goodbye" && s != "Never gonna tell a lie and hurt you" && s != "Never gonna stop") {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
