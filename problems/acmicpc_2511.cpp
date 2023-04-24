#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[10], b[10];
    for(int &i : a) cin >> i; for(int &i : b) cin >> i;
    int last_diff = -1;
    int score_a = 0, score_b = 0;
    for(int i = 0; i < 10; i++) {
        if(a[i] > b[i]) {
            score_a += 3;
            last_diff = i;
        }
        else if(a[i] < b[i]) {
            score_b += 3;
            last_diff = i;
        }
        else {
            score_a++;
            score_b++;
        }
    }
    cout << score_a << ' ' << score_b << '\n';
    if(score_a > score_b) {
        cout << 'A';
    }
    else if(score_a < score_b) {
        cout << 'B';
    }
    else if(last_diff == -1) {
        cout << 'D';
    }
    else if(a[last_diff] > b[last_diff]) {
        cout << 'A';
    }
    else if(a[last_diff] < b[last_diff]) {
        cout << 'B';
    }
}