#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline int dist(pair<int, int> const &a, pair<int, int> const &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            if(x == 1) house.emplace_back(i, j);
            if(x == 2) chicken.emplace_back(i, j);
        }
    }
    int m = 1234567;
    for(int i = 0; i < (1 << chicken.size()); i++) {
        if(__builtin_popcount(i) != k) continue;
        vector<int> mindist(house.size());
        fill(mindist.begin(), mindist.end(), 1987654321);
        for(int j = 0; j < chicken.size(); j++) {
            if(!(i & (1 << j))) continue;
            for(int l = 0; l < house.size(); l++) {
                mindist[l] = min(mindist[l], dist(house[l], chicken[j]));
            }
        } int sum = 0;
        for(int j : mindist) sum += j;
        if(m > sum) m = sum;
    } cout << m;
}