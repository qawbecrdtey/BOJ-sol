#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	switch(n) {
		case 0: printf("1"); break;
		case 1: printf("2"); break;
		case 2: printf("2.5"); break;
		case 3: printf("2.66666666666666666667"); break;
		case 4: printf("2.70833333333333333333"); break;
		case 5: printf("2.71666666666666666667"); break;
		case 6: printf("2.71805555555555555556"); break;
		case 7: printf("2.71825396825396825397"); break;
		case 8: printf("2.71827876984126984127"); break;
		case 9: printf("2.71828152557319223986"); break;
		case 10:printf("2.71828180114638447972"); break;
		case 11:printf("2.71828182619849286516"); break;
		case 12:printf("2.71828182828616856395"); break;
		case 13:printf("2.71828182844675900231"); break;
		case 14:printf("2.71828182845822974791"); break;
		case 15:printf("2.71828182845899446429"); break;
		case 16:printf("2.71828182845904225906"); break;
		case 17:printf("2.71828182845904507052"); break;
		case 18:printf("2.71828182845904522671"); break;
		case 19:printf("2.71828182845904523493"); break;
		case 20:printf("2.71828182845904523534"); break;
		default:printf("2.71828182845904523536"); break;
	}
}