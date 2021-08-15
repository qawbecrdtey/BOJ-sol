#include <iostream>
#include <vector>
using namespace std;
vector<int> prime(int n) {
	vector<int> primes;
	auto visited = new bool[n + 1]();
	for(int i = 2; i * i <= n; i++) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = (i << 1); j <= n; j += i) {
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	return primes;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	auto a = new int[n];
	int max = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(max < a[i]) max = a[i];
	}
	auto primes = prime(max);
	for(int i = 0; i < n; i++) {
		bool flag = false;
		for(auto p : primes) {
			while(a[i] % p == 0) {
				cout << p << ' ';
				a[i] /= p;
			}
			if(a[i] == 1) {
				flag = true;
				break;
			}
		}
		if(!flag) cout << a[i];
		cout << '\n';
	}
	delete[] a;
}