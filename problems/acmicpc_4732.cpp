#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string const str[] { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
    map<string, string> m;
    m["B#"] = "C";
    m["E#"] = "F";
    m["Ab"] = "G#";
    m["Bb"] = "A#";
    m["Cb"] = "B";
    m["Db"] = "C#";
    m["Eb"] = "D#";
    m["Fb"] = "E";
    m["Gb"] = "F#";
    string s; while(true) {
        getline(cin, s);
        if(s == "***") return 0;
        stringstream ss(s);
        vector<int> v;
        string t; while(ss >> t) {
            if(auto it = m.find(t); it != m.end()) t = it->second;
            v.push_back(static_cast<int>(find(str, str + 12, t) - str));
        } getline(cin, t);
        int val = stoi(t);
        for(int &now : v) {
            now = ((now + val) % 12 + 12) % 12;
            cout << str[now] << ' ';
        } cout << '\n';
    }
}