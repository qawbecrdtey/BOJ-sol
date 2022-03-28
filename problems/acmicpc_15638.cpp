#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline vector<int> get_primes() {
    vector<int> primes{ 2, 3 };
    vector<bool> visited(100000);
    int i = 5, d = 4;
    for(; i * i <= 100000; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i; j <= 100000; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i <= 1000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    auto const primes = get_primes();
    int n; cin >> n;
    if(binary_search(primes.begin(), primes.end(), n)) cout << "Yes";
    else cout << "No";
}