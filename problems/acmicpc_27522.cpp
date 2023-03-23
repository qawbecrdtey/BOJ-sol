#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
int main() {
    pair<int, bool> a[8];
    for(auto &i : a) {
        int m, s, ms; char c[2];
        scanf("%d:%d:%d %s", &m, &s, &ms, c);
        i = {m * 60000 + s * 1000 + ms, *c == 'B'};
    } sort(a, a + 8);
    int RB[2]{};
    int const score[8] = {10, 8, 6, 5, 4, 3, 2, 1 };
    for(int i = 0; i < 8; i++) RB[a[i].second] += score[i];
    printf(RB[0] > RB[1] ? "Red" : "Blue");
}