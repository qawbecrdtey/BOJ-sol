#include <cstdio>
constexpr char s[] = "SciComLove";
int main() {
	char c[2]{'\0', '\0'};
	int n; scanf("%d", &n);
	while(n--) {
		printf("%s%s", c, s);
		c[0] = '\n';
	}
}