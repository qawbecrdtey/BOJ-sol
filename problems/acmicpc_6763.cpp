#include <cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if(b - a <= 0) printf("Congratulations, you are within the speed limit!");
	else if(b - a <= 20) printf("You are speeding and your fine is $100.");
	else if(b - a <= 30) printf("You are speeding and your fine is $270.");
	else printf("You are speeding and your fine is $500.");
}