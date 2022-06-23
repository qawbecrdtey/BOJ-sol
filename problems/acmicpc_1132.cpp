#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n;
    pair<long long, bool> a[10]{};
    for(int i = 0; i < n; i++) {
        cin >> s; reverse(s.begin(), s.end());
        long long x = 1;
        for(int j = 0; j < s.size(); j++) {
            a[s[j] - 'A'].first += x;
            if(j == s.size() - 1) a[s[j] - 'A'].second = true;
            x *= 10;
        }
    }
    sort(a, a + 10, [](pair<long long, bool> const &a, pair<long long, bool> const &b) {
        return a.first > b.first;
    }); if(a[9].second) {
        for(int i = 8; i >= 0; i--) {
            if(a[i].second) continue;
            swap(a[i], a[9]);
            break;
        } sort(a, a + 9, [](pair<long long, bool> const &a, pair<long long, bool> const &b) {
            return a.first > b.first;
        });
    }
    long long sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += a[i].first * (9 - i);
    } cout << sum;
}