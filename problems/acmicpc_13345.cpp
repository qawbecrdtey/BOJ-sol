#include <iostream>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int A1=a-c,A2=b-d;//c->a
    int B1=a-e,B2=b-f;//e->a
    int C1=c-e,C2=d-f;//e->c
    if(A1*B1+A2*B2==0){
        int ans1=a-A1-B1;
        int ans2=b-A2-B2;
        std::cout<<ans1<<' '<<ans2;
        return 0;
    }
    if(A1*C1+A2*C2==0){
        int ans1=c+A1-C1;
        int ans2=d+A2-C2;
        std::cout<<ans1<<' '<<ans2;
        return 0;
    }
    if(B1*C1+B2*C2==0){
        int ans1=e+B1+C1;
        int ans2=f+B2+C2;
        std::cout<<ans1<<' '<<ans2;
        return 0;
    }
}