#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string input; getline(cin, input);
        if(input.empty()) getline(cin, input);
        vector<string> v;
        while(true) {
            string s; getline(cin, s);
            if(s == "what does the fox say?") break;
            bool flag = false;
            int idx = 0;
            while(idx < s.size()) {
                if(s[idx] == ' ') {
                    if(flag) break;
                    flag = true;
                }
                idx++;
            }
            v.emplace_back(s.substr(idx + 1));
        } sort(v.begin(), v.end());
        int idx = 0, start = 0;
        while(idx < input.size()) {
            while(idx < input.size() && input[idx] != ' ') idx++;
            string const found = input.substr(start, idx - start);
            if(binary_search(v.begin(), v.end(), found)) { idx++; start = idx; continue; }
            cout << found << ' ';
            idx++; start = idx;
        } cout << '\n';
    }
}