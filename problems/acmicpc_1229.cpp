#include <iostream>
#include <limits>
#include <vector>
using namespace std;
static vector<int> make_six(int n) {
	vector<int> result;
	result.push_back(1);
	int val = 1;
	for(int i = 1; val <= n; i++) {
		val += i * 4 + 1;
		result.push_back(val);
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	auto const six = make_six(n);
	auto a = new int[n + 1];
	std::fill(a + 1, a + n + 1, numeric_limits<int>::max());
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(auto now : six) {
			if(now > i) break;
			if((a[i] = min(a[i], a[i - now] + 1)) == 1) break;
		}
	}
	cout << a[n];
}

