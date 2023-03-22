#include <iostream>
using namespace std;
static constexpr int M = 25*25*25*25*25;
inline bool three_continuous_number(int const a[10]) {
    for(int i = 2; i < 10; i++) {
        if(a[i - 2] == a[i - 1] && a[i - 1] == a[i]) return true;
    } return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[10]; for(int &i : a) {cin >> i; i--;}
    int res = 0;
    for(int i = 0; i < M; i++) {
        int arr[10], x = i;
        for(int &j : arr) { j = x % 5; x /= 5; }
        if(three_continuous_number(arr)) continue;
        int score = 0;
        for(int j = 0; j < 10; j++) {
            score += (a[j] == arr[j]);
        } res += (score >= 5);
    } cout << res;
}