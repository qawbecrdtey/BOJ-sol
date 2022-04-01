#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": ";
        string s; getline(cin, s);
        if(tt == 1) getline(cin, s);
        int a[26]{};
        for(char c : s) {
            if(c >= 'A' && c <= 'Z') a[c - 'A']++;
            if(c >= 'a' && c <= 'z') a[c - 'a']++;
        }
        int min = 1000000000;
        for(auto i : a) {
            if(min > i) min = i;
        }
        if(!min) cout << "Not a pangram\n";
        else if(min == 1) cout << "Pangram!\n";
        else if(min == 2) cout << "Double pangram!!\n";
        else if(min >= 3) cout << "Triple pangram!!!\n";
    }
}