#include <iostream>
using namespace std;
int main() {
    int suma = 0, sumb = 0; for(int i = 0; i < 4; i++) { int x; cin >> x; suma += x; } for(int i = 0; i < 4; i++) { int x; cin >> x; sumb += x; }
    if(suma < sumb) cout << "Emma"; else if(suma > sumb) cout << "Gunnar"; else cout << "Tie";
}