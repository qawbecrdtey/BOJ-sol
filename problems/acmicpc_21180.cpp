#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, sum = 0; cin >> n; auto a = new int[n]; for(int i = 0; i < n; i++) {
        cin >> a[i]; sum += a[i];
    } sort(a, a + n); if(sum & 1 || !binary_search(a, a + n, sum >> 1)) cout << "BAD";
    else cout << (sum >> 1);
}