#include <cstdio>
int main() {
	char c[] = {static_cast<char>(0xEF), static_cast<char>(0xBF), static_cast<char>(0xBD), 0};
	printf("%s", c);
}