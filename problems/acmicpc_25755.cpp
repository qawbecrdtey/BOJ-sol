#include <iostream>
#include <optional>
using namespace std;
inline optional<int> f(int n) {
	switch(n) {
		case 1:
		case 8: return n;
		case 2: return 5;
		case 5: return 2;
		default: return nullopt;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	char c[2]; int n; cin >> c >> n;
	auto a = new optional<int>*[n];
	for(int i = 0; i < n; i++) {
		a[i] = new optional<int>[n];
		for(int j = 0; j < n; j++) {
			int x; cin >> x;
			auto ox = f(x);
			if(ox.has_value()) a[i][j] = ox;
			else a[i][j] = nullopt;
		}
	}
	switch(*c) {
		case 'L':
		case 'R':
			for(int i = 0; i < n; i++) {
				for(int j = n - 1; j >= 0; j--) {
					if(a[i][j].has_value()) cout << *a[i][j] << ' ';
					else cout << "? ";
				} cout << '\n';
			} break;
		case 'U':
		case 'D':
			for(int i = n - 1; i >= 0; i--) {
				for(int j = 0; j < n; j++) {
					if(a[i][j].has_value()) cout << *a[i][j] << ' ';
					else cout << "? ";
				} cout << '\n';
			} break;
		default: __builtin_unreachable();
	}
}