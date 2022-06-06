#include <cstdio>
#include <cstring>
int main() {
	char c[20]; scanf("%s", c);
	int d = c[0] - c[1];
	auto const l = strlen(c);
	for(int i = 2; i < l; i++) {
		if(c[i - 1] - c[i] != d) {
			printf("흥칫뿡!! <(￣ ﹌ ￣)>");
			return 0;
		}
	} printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
}