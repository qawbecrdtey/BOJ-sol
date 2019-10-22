#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    std::getline(cin,s);
    auto it=s.begin();
    while(it!=s.end()){
        printf("%c",*it);
        if(*it!='a'&&*it!='e'&&*it!='i'&&*it!='o'&&*it!='u'){
            it++;
        }
        else it+=3;
    }
}