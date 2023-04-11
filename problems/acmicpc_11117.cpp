#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; int n; cin >> s >> n;
        int a[26]{};
        for(char c : s) a[c - 'A']++;
        while(n--) {
            string ss; cin >> ss;
            int arr[26]{};
            for(char c : ss) arr[c - 'A']++;
            bool flag = true;
            for(int i = 0; i < 26; i++) {
                if(arr[i] > a[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}