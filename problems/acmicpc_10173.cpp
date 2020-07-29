#include <iostream>
#include <string>
using namespace std;
int main(){
    while(true){
        string s;
        std::getline(cin, s);
        if(s=="EOI")break;
        if (s.length() < 4) {
            cout << "Missing" << endl;
            continue;
        }
        auto const l=s.length()-4;
        bool found=false;
        for(int i=0;i<l;i++){
            if(s[i]=='N'||s[i]=='n'){
                i++;
                if(s[i]=='E'||s[i]=='e'){
                    i++;
                    if(s[i]=='M'||s[i]=='m'){
                        i++;
                        if(s[i]=='O'||s[i]=='o'){
                            i++;
                            found=true;
                            break;
                        }
                    }
                }
            }
        }
        cout<<(found?"Found":"Missing")<<endl;
    }
}