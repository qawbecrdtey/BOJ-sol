#include <iostream>
#include <vector>
using ll = long long;
constexpr ll M = 100000000;
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	auto a = new ll*[n + 1];
	for(int i = 1; i <= n; i++) {
		a[i] = new ll[n + 1];
		for(int j = 1; j <= n; j++) {
			if(i == j) a[i][j] = 0;
			else a[i][j] = M;
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		a[x][y] = z;
	}
	for(int i = 1; i <= n; i++) {
		for(int s = 1; s <= n; s++) {
			for(int e = 1; e <= n; e++) {
				if(a[s][e] > a[s][i] + a[i][e]) {
					a[s][e] = a[s][i] + a[i][e];
				}
			}
		}
	}
	int k;
	std::cin >> k;
	auto arr = new ll[n + 1]();
	for(int i = 0; i < k; i++) {
		int x;
		std::cin >> x;
		for(int j = 1; j <= n; j++) {
			if(arr[j] < a[x][j] + a[j][x]) arr[j] = a[x][j] + a[j][x];
		}
	}
	int mini = 1;
	std::vector<int> v = { 1 };
	for(int i = 2; i <= n; i++) {
		if(arr[mini] > arr[i]) {
			mini = i;
			v.clear();
			v.push_back(mini);
		}
		else if(arr[mini] == arr[i]) {
			v.push_back(i);
		}
	}
	for(auto now : v) {
		std::cout << now << ' ';
	}
	delete[] arr;
	for(int i = 1; i <= n; i++) {
		delete[] a[i];
	}
	delete[] a;
}