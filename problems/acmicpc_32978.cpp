#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    set<string> s;
    for(int i = 0; i < n; i++) {
        string t; cin >> t; s.insert(std::move(t));
    }
    for(int i = 1; i < n; i++) {
        string t; cin >> t; s.erase(t);
    }
    cout << *s.begin();
}
