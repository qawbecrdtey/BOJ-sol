#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n%4){
		putchar('0');
	}
	else if(n%100){
		putchar('1');
	}
	else if(n%400){
		putchar('0');
	}
	else{
		putchar('1');
	}
}