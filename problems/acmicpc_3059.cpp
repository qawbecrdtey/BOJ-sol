#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        bool a[26]={};
        string s;
        int sum=0;
        cin>>s;
        for(char c:s){
            a[c-'A']=true;
        }
        for(int i=0;i<26;i++){
            if(!a[i])sum+=i+'A';
        }
        cout<<sum<<endl;
    }
}