#include <iostream>
using namespace std;
int main(){
    constexpr double pi=3.141592653589793238462643383279502884197169399375105820974944;
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a*d<pi*c*c*b)cout<<"Whole pizza";
    else cout<<"Slice of pizza";
}