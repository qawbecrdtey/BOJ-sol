#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n, k; string s;
	cin >> n >> k >> s;
	vector<int> v;
	for(int i = 0; i < s.size();) {
		auto const start = i;
		while(i < s.size() && s[i] != ',') i++;
		v.push_back(stoi(s.substr(start, i - start)));
		i++;
	}
	while(k--) {
		vector<int> vv;
		for(int i = 1; i < v.size(); i++) {
			vv.push_back(v[i] - v[i - 1]);
		}
		v = move(vv);
	}
	for(int i = 0; i < v.size() - 1; i++) {
		cout << v[i] << ',';
	} cout << v.back();
}