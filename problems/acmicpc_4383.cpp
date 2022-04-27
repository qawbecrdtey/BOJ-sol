#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; while(cin >> n) {
		auto a = new long long[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		if(n == 1) {
			cout << "Jolly\n";
			delete[] a;
			continue;
		}
		auto visited = new bool[n - 1]();
		for(int i = 1; i < n; i++) {
			long long const x = abs(a[i] - a[i - 1]);
			if(!x || x > n - 1 || visited[x - 1]) {
				cout << "Not jolly\n";
				goto END;
			}
			visited[x - 1] = true;
		}
		cout << "Jolly\n";
	END:delete[] visited;
		delete[] a;
	}
}