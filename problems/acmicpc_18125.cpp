#include <iostream>
using namespace std;
void print(bool b) {
	if (b)
		cout << "|>___/|        /}\n"
				"| O < |       / }\n"
				"(==0==)------/ }\n"
				"| ^  _____    |\n"
				"|_|_/     ||__|";
	else
		cout << "|>___/|     /}\n"
				"| O O |    / }\n"
				"( =0= )\"\"\"\"  \\\n"
				"| ^  ____    |\n"
				"|_|_/    ||__|";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	auto b = new int *[m];
	for (int i = 0; i < m; i++) {
		b[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	auto a = new int *[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] != b[m - j - 1][i]) {
				print(false);
				return 0;
			}
		}
	}
	print(true);
}