#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes() {
    vector<int> primes{2, 3};
    vector<bool> visited(1000001);
    int i = 5, d = 4;
    for(; i <= 1000; i += (d = 6 - d)) {
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i * 3; j <= 1000000; j += (i << 1)) visited[j] = true;
        }
    }
    for(; i <= 1000000; i += (d = 6 - d)) {
        if(!visited[i]) primes.push_back(i);
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto const primes = get_primes();
    auto a = new int*[n * n];
    for(int i = 0; i < n * n; i++) {
        a[i] = new int[n * n];
        for(int j = 0; j < n * n; j++) {
            cin >> a[i][j];
        }
    }
    auto used = new bool[primes.size()]();
    for(int i = 0; i < n * n; i++) {
        for(int j = 0; j < n * n; j++) {
            if(a[i][j] < 2) continue;
            int val = a[i][j];
            for(int k = 0; k < primes.size() && primes[k] * primes[k] <= val; k++) {
                if(val % primes[k]) continue;
                used[k] = true;
                while(val % primes[k] == 0) val /= primes[k];
            }
            if(val != 1) {
                used[lower_bound(primes.begin(), primes.end(), val) - primes.begin()] = true;
            }
        }
    }
    int idx = 0;
    for(int i = 0; i < n * n; i++) {
        for(int j = 0; j < n * n; j++) {
            if(a[i][j]) { cout << a[i][j] << ' '; continue; }
            while(used[idx]) idx++;
            a[i][j] = primes[idx++];
            cout << a[i][j] << ' ';
        } cout << '\n';
    }
}