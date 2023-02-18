#include <cstdio>
#include <cstring>
int main() {
    char c[20]; long long res = 0;
    while(scanf("%s", c) != EOF) {
        if(c[0] == 'E' && c[1] == 'O' && c[2] == 'I') break;
        if(!strcmp(c, "Paper")) res += 5799;
        else if(!strcmp(c, "Printer")) res += 12050;
        else if(!strcmp(c, "Planners")) res += 3125;
        else if(!strcmp(c, "Binders")) res += 2250;
        else if(!strcmp(c, "Calendar")) res += 1095;
        else if(!strcmp(c, "Notebooks")) res += 1120;
        else if(!strcmp(c, "Ink")) res += 6695;
    } printf("$%lld.%02lld", res / 100, res % 100);
}