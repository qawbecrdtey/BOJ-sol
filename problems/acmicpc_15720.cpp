#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[3]; for(int &i : a) cin >> i;
    int sum = 0;
    int *arr[3]; for(int i = 0; i < 3; i++) {
        arr[i] = new int[a[i]];
        for(int j = 0; j < a[i]; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
        sort(arr[i], arr[i] + a[i], [](int a, int b) { return a > b; });
    } cout << sum << '\n';
    for(int i = 0; i < a[0] && i < a[1] && i < a[2]; i++) {
        for(auto &j : arr) j[i] = j[i] / 10 * 9;
    } sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < a[i]; j++) {
            sum += arr[i][j];
        }
    } cout << sum;
}