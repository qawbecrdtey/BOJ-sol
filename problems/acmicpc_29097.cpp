#include <algorithm>
#include <iostream>
using namespace std;
struct info {
    char const *name;
    long long val;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long n, m, k, a, b, c; cin >> n >> m >> k >> a >> b >> c;
    info arr[3] {{"Joffrey", n * a}, {"Robb", m * b}, {"Stannis", k * c}};
    sort(arr, arr + 3, [](info const &a, info const &b) {
        return a.val > b.val || (a.val == b.val && *a.name < *b.name);
    });
    cout << arr[0].name;
    for(int i = 1; i < 3; i++) {
        if(arr[i].val < arr[i - 1].val) break;
        cout << ' ' << arr[i].name;
    }
}
