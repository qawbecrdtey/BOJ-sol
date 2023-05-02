#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        double height = 0;
        vector<string> v;
        while(n--) {
            string s; double h; cin >> s >> h;
            if(h > height) {
                v.clear();
                v.push_back(s);
                height = h;
            }
            else if(h == height) {
                v.push_back(s);
            }
        }
        for(auto const &now : v) cout << now << ' ';
        cout << '\n';
    }
}