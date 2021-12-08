#include <cstdio>
void blank(int n) {
	if(!n) {
		putchar(' ');
		return;
	}
	blank(n - 1);
	blank(n - 1);
	blank(n - 1);
}
void part(int n) {
	if(!n) {
		putchar('-');
		return;
	}
	part(n - 1);
	blank(n - 1);
	part(n - 1);
}
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		part(n);
		putchar('\n');
	}
}