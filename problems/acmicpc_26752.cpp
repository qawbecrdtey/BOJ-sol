#include <iostream>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    if(++c >= 60) c -= 60, b++;
    if(b >= 60) b -= 60, a++;
    if(a >= 24) a -= 24;
    printf("%02d:%02d:%02d", a, b, c);
}