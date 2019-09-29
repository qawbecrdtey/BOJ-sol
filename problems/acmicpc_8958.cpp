#include <iostream>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int const l=s.length();
        int cnt=0;
        int score=0;
        for(int i=0;i<l;i++){
            if(s[i]=='O'){
                cnt++;
                score+=cnt;
            }
            else{
                cnt=0;
            }
        }
        cout<<score<<endl;
    }
}