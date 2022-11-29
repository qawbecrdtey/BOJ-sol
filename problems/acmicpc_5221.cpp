#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
struct triple {
	ll x, y, z;
	[[nodiscard]] string to_string() const {
		return '{' + std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z) + '}';
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n; cin >> n;
		auto a = new ll[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		} sort(a, a + n);
		vector<triple> v;
		for(int i = 0; i < n - 2; i++) {
			for(int j = i + 1; j < n - 1; j++) {
				ll const x = a[i] * a[i] + a[j] * a[j];
				int l = j + 1, r = n;
				while(l < r) {
					int const m = (l + r) / 2;
					if(a[m] * a[m] == x) {
						v.push_back({ a[i], a[j], a[m] });
						break;
					}
					if(a[m] * a[m] < x) l = m + 1;
					else r = m;
				}
			}
		}
		if(v.empty()) cout << "No Pythogorean triples found in the sequence.\n";
		else {
			sort(v.begin(), v.end(), [](triple const &a, triple const &b) { return a.to_string() < b.to_string(); });
			cout << "Found Pythogorean triples: ";
			for(auto const &now : v) {
				cout << " {" << now.x << ' ' << now.y << ' ' << now.z << '}';
			} cout << '\n';
		}
		delete[] a;
	}
}