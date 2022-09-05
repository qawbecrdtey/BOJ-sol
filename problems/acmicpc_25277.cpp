#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		cnt += (s == "he" || s == "she" || s == "him" || s == "her");
	} cout << cnt;
}