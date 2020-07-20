#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string *s=new string[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int j=m-1;j>=0;j--){
        for(int i=0;i<n;i++){
            switch(s[i][j]){
                case '.':printf(".");break;
                case 'O':printf("O");break;
                case '-':printf("|");break;
                case '|':printf("-");break;
                case '/':printf("\\");break;
                case '\\':printf("/");break;
                case '^':printf("<");break;
                case '<':printf("v");break;
                case 'v':printf(">");break;
                case '>':printf("^");break;
                default:break;
            }
        }
        printf("\n");
    }
    delete[] s;
}