#include <algorithm>
#include <cstdio>
void mul(bool const a[26][26], bool const b[26][26], bool c[26][26]) {
	for(int i = 0; i < 26; i++) {
		for(int j = 0; j < 26; j++) {
			c[i][j] = false;
			for(int k = 0; k < 26 && !c[i][j]; k++) {
				c[i][j] = c[i][j] || (a[i][k] && b[k][j]);
			}
		}
	}
}
void power(bool a[26][26], int n) {
	if(!n) {
		for(int i = 0; i < 26; i++) {
			for(int j = 0; j < 26; j++) {
				a[i][j] = (i == j);
			}
		} return;
	}
	if(n == 1) return;
	bool b[26][26];
	bool c[26][26];
	for(int i = 0; i < 26; i++) {
		std::copy(a[i], a[i] + 26, b[i]);
		std::copy(a[i], a[i] + 26, c[i]);
	}
	power(b, n >> 1);
	mul(b, b, a);
	if(n & 1) {
		mul(a, c, b);
		for(int i = 0; i < 26; i++) {
			std::copy(b[i], b[i] + 26, a[i]);
		}
	}
}
int main() {
	int n; scanf("%d", &n);
	bool a[26][26]{};
	for(int i = 0; i < 26; i++) a[i][i] = true;
	for(int i = 0; i < n; i++) {
		char b[2], c[2];
		scanf("%s is %s", b, c);
		a[*b - 'a'][*c - 'a'] = true;
	} power(a, 26);
	int m; scanf("%d", &m);
	while(m--) {
		char b[2], c[2];
		scanf("%s is %s", b, c);
		printf(a[*b - 'a'][*c - 'a'] ? "T\n" : "F\n");
	}
}