#include <stdio.h>
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int x=b%10;
	printf("%d\n",a*x);
	x=(b/10)%10;
	printf("%d\n",a*x);
	x=(b/100)%10;
	printf("%d\n",a*x);
	printf("%d",a*b);
}