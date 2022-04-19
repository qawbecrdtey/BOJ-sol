#include <cstdio>
int main() {
	int x = 0, y;
	for(int i = 0; i < 3; i++) {
		scanf("%d", &y);
		x |= (y << i);
	} switch(x) {
		case 0:
		case 7: printf("*"); break;
		case 1:
		case 6: printf("A"); break;
		case 2:
		case 5: printf("B"); break;
		case 3:
		case 4: printf("C"); break;
		default: __builtin_unreachable();
	}
}