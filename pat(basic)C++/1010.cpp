#include <iostream>
using namespace std;
#include<stdio.h>
int main(){
    int coefficient;
    int index;
    int flag = 0;
    cin>>coefficient;
    cin>>index;
    while(1){
        if((index!=0&&index!=1)||(index==1&&coefficient!=0)){
            coefficient *= index;
            index -=1;
            flag++;
            if(flag!=1){
                cout<<' ';
            }
            cout<<coefficient<<' '<<index;
        }
        coefficient = 0;
        index = 0;
        char ch = cin.get();
        if(ch=='\n'){
            break;
        }
        cin>>coefficient;
        cin>>index;
    }
    return 0;
}
