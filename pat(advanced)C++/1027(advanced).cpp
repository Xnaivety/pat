#include<iostream>
using namespace std;


void radixconv(int a){
    string b;
    for(int i = 0;i<2;i++){
        if(a/13==10){
            cout<<'A';
        }
        else if(a/13==11){
            cout<<'B';
        }
        else if(a/13==12){
            cout<<'C';
        }
        else{
            cout<<(char)(a/13);
        }
        a = a%13;
    }
}
int main(){
    int red;
    int green;
    int blue;
    cin>>red>>green>>blue;
    cout<<'#';
    radixconv(red);
    radixconv(green);
    radixconv(blue);
    return 0;
}