#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,r,c;
    cin>>n>>r>>c;
    bool b;
    if((r+c)%2){
        b=false;
    }
    else b=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(b^((i+j)%2==0) ? "." : "v");
        }
        cout<<endl;
    }
}