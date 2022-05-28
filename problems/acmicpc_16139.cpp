#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	array<int*, 26> arr{};
	for(auto &i : arr) i = new int[s.size() + 1]();
	for(int i = 0; i < s.size(); i++) {
		for(int j = 0; j < 26; j++) {
			arr[j][i + 1] = arr[j][i] + (s[i] - 'a' == j);
		}
	}
	int q; cin >> q; while(q--) {
		char c[2]; int x, y; cin >> c >> x >> y;
		printf("%d\n", arr[*c - 'a'][y + 1] - arr[*c - 'a'][x]);
	}
}