#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	auto a = new int**[s[0].size() + 1];
	int max = 0;
	for(int i = 0; i <= s[0].size(); i++) {
		a[i] = new int*[s[1].size() + 1];
		for(int j = 0; j <= s[1].size(); j++) {
			a[i][j] = new int[s[2].size() + 1]();
			for(int k = 0; k <= s[2].size(); k++) {
				if(i && j && k && s[0][i - 1] == s[1][j - 1] && s[1][j - 1] == s[2][k - 1]) {
					a[i][j][k] = a[i - 1][j - 1][k - 1] + 1;
					if(max < a[i][j][k]) max = a[i][j][k];
				}
				else {
					if(i) a[i][j][k] = a[i - 1][j][k];
					if(j && a[i][j][k] < a[i][j - 1][k]) a[i][j][k] = a[i][j - 1][k];
					if(k && a[i][j][k] < a[i][j][k - 1]) a[i][j][k] = a[i][j][k - 1];
				}
			}
		}
	}
	cout << max;
	for(int i = 0; i <= s[0].size(); i++) {
		for(int j = 0; j <= s[1].size(); j++) {
			delete[] a[i][j];
		}
		delete[] a[i];
	}
	delete[] a;
}