#include <iostream>
#include <string>
#include <vector>
using namespace std;
string to_lower(string s) {
    for(char &c : s) {
        if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }
    return s;
}
bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-';
}
vector<string> split(string s) {
    int start = 0;
    vector<string> result;
    for(int i = 0; i < s.size(); i++) {
        if(!is_letter(s[i])) {
            if(start != i) {
                result.push_back(s.substr(start, i - start + 1));
            }
            start = i + 1;
        }
    }
    result.push_back(s.substr(start));
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string res;
    string s; while(cin >> s) {
        if(s == "E-N-D") break;
        auto v = split(s);
        for(auto const &now : v) {
            if(res.size() < now.size()) res = now;
        }
    } cout << to_lower(res);
}
