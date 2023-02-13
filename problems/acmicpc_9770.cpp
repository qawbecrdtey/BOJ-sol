#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<int> v; int x; while(cin >> x) v.push_back(x);
    int m = 0; for(int i = 0; i < v.size(); i++) for(int j = 0; j < i; j++) m = max(m, gcd(v[i], v[j]));
    cout << m;
}