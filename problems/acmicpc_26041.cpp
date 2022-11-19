#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	vector<string> v; string s; int cnt{};
	while(cin >> s) v.push_back(std::move(s));
	for(auto const &st : v) {
		cnt += (st.size() > v.back().size() && st.substr(0, v.back().size()) == v.back());
	} cout << cnt;
}