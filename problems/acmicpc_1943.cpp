#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t = 3; while(t--) {
        int n; cin >> n; auto a = new pair<int, int>[n];
        int sum = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            sum += a[i].first * a[i].second;
            cnt += a[i].second;
        }
        if(sum & 1) { cout << "0\n"; continue; }
        sum >>= 1;
        bitset<50001> bits;
        bits[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a[i].second; j++) {
                bits |= (bits << a[i].first);
            }
        }
        cout << bits[sum] << '\n';
    }
}
