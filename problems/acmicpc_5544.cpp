#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    auto arr = new pair<int, int>[n + 1]();
    for(int i = 1; i <= n; i++) arr[i].second = i;
    for(int i = 0; i < (n * (n - 1)) / 2; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(c == d) {
            arr[a].first++; arr[b].first++;
            continue;
        }
        if(c > d) {
            arr[a].first += 3;
            continue;
        }
        arr[b].first += 3;
    }
    sort(arr + 1, arr + n + 1, [](pair<int, int> const &a, pair<int, int> const &b) {
        return a.first > b.first;
    });
    int prev = 0;
    for(int i = 1; i <= n; i++) {
        if(prev != arr[i].first) {
            prev = arr[i].first;
            arr[i].first = i;
        }
        else {
            arr[i].first = arr[i - 1].first;
        }
    }
    sort(arr + 1, arr + n + 1, [](pair<int, int> const &a, pair<int, int> const &b) {
        return a.second < b.second;
    });
    for(int i = 1; i <= n; i++) {
        printf("%d\n", arr[i].first);
    }
}