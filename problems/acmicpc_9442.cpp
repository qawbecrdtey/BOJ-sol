#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n; string s;
    int year = 0;
    while(true) {
        cin >> n;
        if(!n) return 0;
        cin >> s;
        cout << "year " << ++year << '\n';
        int arr[26];
        for(int i = 0; i < 26; i++) {
            arr[s[i] - 'A'] = i;
        }
        auto sarr = new string[n];
        for(int i = 0; i < n; i++) cin >> sarr[i];
        sort(sarr, sarr + n, [&arr](string const &a, string const &b) {
            for(int i = 0; i < a.size() && i < b.size(); i++) {
                if(arr[a[i] - 'A'] < arr[b[i] - 'A']) return true;
                if(arr[b[i] - 'A'] < arr[a[i] - 'A']) return false;
            }
            return a.size() < b.size();
        });
        for(int i = 0; i < n; i++) cout << sarr[i] << '\n';
        delete[] sarr;
    }
}